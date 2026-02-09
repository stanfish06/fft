#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use std::env;
use std::fmt;
use std::fs;
use std::str;
use num::complex::Complex;

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

static complex_i: Complex<f32> = Complex::new(0.0, -1.0);

// TODO: this code works specifically for 4 x 4, need to implement general formula
pub fn construct_dft_matrix(n: u64) -> Vec<Complex<f32>> {
    let mut dft_matrix: Vec<Complex<f32>> = Vec::new();
    for i in 0..n {
        for j in 0..n {
            let _entry = complex_i.powi((i * j).try_into().unwrap());
            // println!("{}", _entry);
            dft_matrix.push(_entry);
        }
    }
    return dft_matrix;
}

fn main() {
    let mut dft_matrix = construct_dft_matrix(4);
    let f_real = vec![-1.0, 0.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0];
    let mut f_complex: Vec<Complex<f32>> = f_real.iter().map(|x| x.into()).collect();
    unsafe{
        let mut dft_matrix_c: *mut Matrix = create_matrix(4, 4, dft_matrix.as_mut_ptr() as *mut __BindgenComplex<f32>);
        let mut f_matrix_c: *mut Matrix = create_matrix(4, 2, f_complex.as_mut_ptr() as *mut __BindgenComplex<f32>);
        let mut f_transformed_c: *mut Matrix = matrix_dot(dft_matrix_c, f_matrix_c);
        let nrow = (*f_transformed_c).nrow;
        let ncol = (*f_transformed_c).ncol;
        let result: &[Complex<f32>] = std::slice::from_raw_parts(
            (*f_transformed_c).data as *const Complex<f32>,
            nrow * ncol,
        );
        println!("{:?}", result);
    }
}

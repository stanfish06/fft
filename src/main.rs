#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use std::env;
use std::fmt;
use std::fs;
use std::str;
use num::complex::Complex;

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

static complex_i: Complex<f64> = Complex::new(0.0, 1.0);

pub fn construct_dft_matrix(n: u64) -> Vec<Complex<f64>> {
    let mut dft_matrix: Vec<Complex<f64>> = Vec::new();
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
    construct_dft_matrix(4);
}

struct Matrix<T> {
    pub nrow: usize,
    pub ncol: usize,
    data: Vec<T>,
}

impl<T: Default> Matrix<T> {
    pub fn new() -> Self {
        Self {
            nrow: 0,
            ncol: 0,
            data: vec![],
        }
    }
    pub fn from_vec(data: Vec<T>, nrow: usize, ncol: usize) -> Self {
        Self { nrow, ncol, data }
    }
    pub fn resize(&mut self, nrow: usize, ncol: usize) {
        self.nrow = nrow;
        self.ncol = ncol;
    }
}

impl<T> std::ops::Index<[usize; 2]> for Matrix<T> {
    type Output = T;
    fn index(&self, index: [usize; 2]) -> &Self::Output {
        &self.data[index[0] * self.ncol + index[1]]
    }
}

fn main() {
    let mut m = Matrix::from_vec(vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], 4, 3);
    m.resize(3, 4);
    for i in 0..m.nrow {
        for j in 0..m.ncol {
            print!("{:2} ", m[[i, j]]);
        }
        println!();
    }
}

fn main() {
    // let p_x = &mut 5;
    // *p_x = 10;
    // println!("{}", p_x);
    // let mut p_x = Box::new(5);
    // *p_x = 10;
    // println!("{}", p_x);
    let mut i = 0;
    let j = while i < 5 {
        if i == 3 {
            break i * 2;
        }
    };
    assert_eq!(j, 6);
}
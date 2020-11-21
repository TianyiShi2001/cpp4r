pub trait Pet {
    fn speak(&self) -> &'static str;
    fn name(&self) -> &str;
    fn say_hi(&self) {
        println!("{} says: \"{}\"", self.name(), self.speak());
    }
}

macro_rules! make_pet {
    ($pet_type:ident, $speak:expr) => {
        pub struct $pet_type {
            name: String,
        }

        impl $pet_type {
            fn new(name: impl Into<String>) -> Self {
                Self { name: name.into() }
            }
        }

        impl Pet for $pet_type {
            fn speak(&self) -> &'static str {
                $speak
            }
            fn name(&self) -> &str {
                &self.name
            }
        }
    };
}

make_pet!(Dog, "Woof");
make_pet!(Cat, "Meow");

fn pet_say_hi(pet: &dyn Pet) {
    pet.say_hi();
}

fn main() {
    let coco = Dog::new("Coco");
    let yuki = Cat::new("Yuki");
    coco.say_hi();
    yuki.say_hi();
    pet_say_hi(&coco);
    pet_say_hi(&yuki);
}

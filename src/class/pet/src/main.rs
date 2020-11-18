pub trait Pet {
    fn speak(&self) -> &'static str;
    fn name(&self) -> &str;
    fn say_hi(&self) {
        println!("{} says: \"{}\"", self.name(), self.speak());
    }
}

pub struct Dog {
    name: String,
}

impl Dog {
    fn new(name: impl Into<String>) -> Self {
        Self { name: name.into() }
    }
}

impl Pet for Dog {
    fn speak(&self) -> &'static str {
        "Woof"
    }
    fn name(&self) -> &str {
        &self.name
    }
}

pub struct Cat {
    name: String,
}

impl Cat {
    fn new(name: impl Into<String>) -> Self {
        Self { name: name.into() }
    }
}

impl Pet for Cat {
    fn speak(&self) -> &'static str {
        "Meow"
    }
    fn name(&self) -> &str {
        &self.name
    }
}

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

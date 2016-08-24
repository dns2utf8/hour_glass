pub struct IntSorter {
  data : Vec<i64>,
  sorted: bool,
}

impl IntSorter {
  fn put(&mut self, i : i64) {
    self.data.push(i);
  }

  fn get(&mut self) -> i64 {
    self.data.pop().unwrap()
  }
}

#[no_mangle]
pub extern "C" fn sorter_new() -> Box<IntSorter> {
  Box::new(IntSorter{ data: vec![], sorted: true })
}

#[no_mangle]
pub extern "C" fn sorter_cleanup(s : Box<IntSorter>) {
  // Destroy
  drop(s);
}


#[no_mangle]
pub extern "C" fn sorter_put(s : &mut IntSorter, i : i64) {
  s.put(i);
  s.sorted = false;
}


#[no_mangle]
pub extern "C" fn sorter_get(s : &mut IntSorter) -> i64 {
  if s.sorted == false {
    s.data.sort();
    s.sorted = true;
  }
  s.get()
}


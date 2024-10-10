class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

class SinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }
  push(val) {
    const newNode = new Node(val);
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this.length++;
    return this;
  }

  pop() {
    if (!this.head) return undefined;
    let curNode = this.head;
    let newTail = curNode;
    while (curNode.next) {
      newTail = curNode;
      curNode = curNode.next;
    }
    this.tail = newTail;
    this.tail.next = null;
    this.length--;
    if (this.length === 0) {
      this.head = null;
      this.tail = null;
    }
    return curNode;
  }

  unshift(val) {
    const newNode = new Node(val);
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      newNode.next = this.head;
      this.head = newNode;
    }
    this.length++;
    return this;
  }

  shift() {
    if (!this.head) return undefined;
    const curHead = this.head;
    this.head = curHead.next;
    this.length--;
    if (this.length === 0) {
      this.head = null;
      this.tail = null;
    }
    return curHead;
  }

  get(index) {
    if (index < 0 || index >= this.length) return undefined;
    let cnt = 0;
    let curNode = this.head;
    while (cnt !== index) {
      curNode = curNode.next;
      cnt++;
    }
    return curNode;
  }

  set(index, val) {
    const foundNode = this.get(index);
    if (!foundNode) return false;
    foundNode.val = val;
    return true;
  }

  insert(index, val) {
    if (index < 0 || index > this.length) return false;
    if (index === this.length) return !!this.push(val);
    if (index === 0) return !!this.unshift(val);

    const newNode = new Node(val);
    const prev = this.get(index - 1);
    const temp = prev.next;
    prev.next = newNode;
    newNode.next = temp;
    this.length++;
    return true;
  }

  remove(index) {
    if (index < 0 || index >= this.length) return undefined;
    if (index === 0) return this.shift();
    if (index === this.length - 1) return this.pop();

    const prevNode = this.get(index - 1);
    const removed = prevNode.next;
    prevNode.next = removed.next;
    this.length--;
    return removed;
  }

  reverse() {
    let node = this.head;
    this.head = this.tail;
    this.tail = node;
    let next;
    let prev = null;
    for (let i = 0; i < this.length; ++i) {
      next = node.next;
      node.next = prev;
      prev = node;
      node = next;
    }
    return this;
  }

  print() {
    const arr = [];
    let curNode = this.head;
    while (curNode) {
      arr.push(curNode.val);
      curNode = curNode.next;
    }
    console.log(arr);
  }
}

const list = new SinglyLinkedList();

// 1. Push 메서드 테스트
console.log('1. Push 테스트:');
list.push(1);
list.push(2);
list.push(3);
list.print(); // [1, 2, 3]

// 2. Pop 메서드 테스트
console.log('2. Pop 테스트:');
console.log(list.pop()); // 3
list.print(); // [1, 2]

// 3. Unshift 메서드 테스트
console.log('3. Unshift 테스트:');
list.unshift(0);
list.unshift(-1);
list.print(); // [-1, 0, 1, 2]

// 4. Shift 메서드 테스트
console.log('4. Shift 테스트:');
console.log(list.shift()); // -1
list.print(); // [0, 1, 2]

// 5. Get 메서드 테스트
console.log('5. Get 테스트:');
console.log(list.get(0)); // 0
console.log(list.get(1)); // 1
console.log(list.get(2)); // 2
console.log(list.get(3)); // undefined

// 6. Set 메서드 테스트
console.log('6. Set 테스트:');
console.log(list.set(1, 'two')); // true
console.log(list.get(1)); // 'two'

// 7. Insert 메서드 테스트
console.log('7. Insert 테스트:');
list.insert(1, 'inserted');
list.print(); // [0, 'inserted', 'two', 2]

// 8. Remove 메서드 테스트
console.log('8. Remove 테스트:');
list.remove(1);
list.print(); // [0, 'two', 2]

// 9. Reverse 메서드 테스트
console.log('9. Reverse 테스트:');
list.reverse();
list.print(); // [2, 'two', 0]

// 10. 전체 리스트 출력
console.log('10. 전체 리스트 출력:');
list.print();

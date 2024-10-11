let queue = [];

// #1 push shift
queue.push(1);
queue.push(2);
queue.push(3);
console.log(queue); // [ 1, 2, 3 ]

console.log(queue.shift()); // 1
console.log(queue.shift()); // 2
console.log(queue.shift()); // 3
console.log(queue); // []

// #2 unsift pop

queue.unshift('one');
queue.unshift('two');
queue.unshift('three');
console.log(queue); // [ 'three', 'two', 'one' ]

console.log(queue.pop()); // one
console.log(queue.pop()); // two
console.log(queue.pop()); // three
console.log(queue); // []

// #3 queue calss 1
class Queue1 {
  items = [];
  front = 0;
  rear = 0;

  constructor(array) {
    this.items = array;
    this.rear = array.length;
  }

  enQueue(item) {
    this.items.push(item);
    this.rear++;
  }

  deQueue() {
    if (this.isEmpty()) {
      return 'Queue is empty';
    }
    return this.items[this.front++];
  }
  getFront() {
    if (this.isEmpty()) {
      return 'Queue is empty';
    }
    return this.items[this.front];
  }
  getRear() {
    if (this.isEmpty()) {
      return 'Queue is empty';
    }
    return this.items[this.rear - 1];
  }
  size() {
    return this.rear - this.front;
  }
  isEmpty() {
    return this.front === this.rear;
  }
  print() {
    return console.log(this.items.slice(this.front, this.rear));
  }
}

queue = new Queue1([1, 2, 3]);

// 1. Push 테스트
console.log('1. Push 테스트:');
queue.enQueue(4);
queue.print(); // [1, 2, 3, 4]

// 2. Pop 테스트
console.log('2. Pop 테스트:');
console.log(queue.deQueue()); // 1
console.log(queue.deQueue()); // 2
queue.print(); // [3, 4]

// 3. GetFront 테스트
console.log('3. GetFront 테스트:');
console.log(queue.getFront()); // 3
queue.print(); // [3, 4]

// 4. Size 테스트
console.log('4. Size 테스트:');
console.log(queue.size()); // 2

// 5. IsEmpty 테스트
console.log('5. IsEmpty 테스트:');
console.log(queue.isEmpty()); // false
queue.deQueue();
queue.deQueue();
console.log(queue.isEmpty()); // true

// 6. GetRear 테스트
console.log('6. GetRear 테스트:');
queue.enQueue(5);
queue.enQueue(6);
console.log(queue.getRear()); // 6
queue.print(); // [5, 6]

// 7. Print 테스트
console.log('7. Print 테스트:');
queue.enQueue(7);
queue.print(); // [5, 6, 7]

// #3 queue calss 2
class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}
class Queue2 {
  constructor() {
    this.front = null;
    this.rear = null;
    this.capacity = 0;
  }

  enQueue(val) {
    const newNode = new Node(val);
    if (!this.front) {
      this.front = newNode;
      this.rear = newNode;
    } else {
      this.rear.next = newNode;
      this.rear = newNode;
    }
    return ++this.capacity;
  }

  deQueue() {
    if (!this.front) return null;

    const temp = this.front;
    if (this.front === this.rear) {
      this.rear = null;
    }
    this.front = this.front.next;
    this.capacity--;
    return temp.val;
  }

  getFront() {
    return this.front ? this.front.val : null;
  }

  getRear() {
    return this.rear ? this.rear.val : null;
  }

  size() {
    return this.capacity;
  }

  isEmpty() {
    return this.capacity === 0;
  }

  print() {
    const arr = [];
    let curNode = this.front;
    while (curNode) {
      arr.push(curNode.val);
      curNode = curNode.next;
    }
    console.log(arr);
  }
}

// Queue2 테스트 코드
const queue2 = new Queue2();

// 1. Push 테스트
console.log('1. Push 테스트:');
queue2.enQueue('apple');
queue2.enQueue('banana');
queue2.enQueue('cherry');
queue2.print(); // ['apple', 'banana', 'cherry']

// 2. Pop 테스트
console.log('2. Pop 테스트:');
console.log(queue2.deQueue()); // 'apple'
console.log(queue2.deQueue()); // 'banana'
queue2.print(); // ['cherry']

// 3. GetFront 테스트
console.log('3. GetFront 테스트:');
console.log(queue2.getFront()); // 'cherry'
queue2.print(); // ['cherry']

// 4. Size 테스트
console.log('4. Size 테스트:');
console.log(queue2.size()); // 1

// 5. IsEmpty 테스트
console.log('5. IsEmpty 테스트:');
console.log(queue2.isEmpty()); // false
queue2.deQueue();
console.log(queue2.isEmpty()); // true

// 6. GetRear 테스트
console.log('6. GetRear 테스트:');
queue2.enQueue('grape');
queue2.enQueue('orange');
console.log(queue2.getRear()); // 'orange'
queue2.print(); // ['grape', 'orange']

// 7. Print 테스트
console.log('7. Print 테스트:');
queue2.enQueue('pineapple');
queue2.print(); // ['grape', 'orange', 'pineapple']

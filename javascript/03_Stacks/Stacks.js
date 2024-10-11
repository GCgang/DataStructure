let stack = [];

// #1 push, pop
stack.push('google');
stack.push('youtube');
stack.push('naver');
console.log(stack); // [ 'google', 'youtube', 'naver' ]

console.log(stack.pop()); // naver
console.log(stack.pop()); // youbue
console.log(stack.pop()); // google
console.log(stack); // []

// #2 unshift, shift
stack.unshift(1);
stack.unshift(2);
stack.unshift(3);
console.log(stack); // [ 3, 2, 1 ]

console.log(stack.shift()); // 3
console.log(stack.shift()); // 2
console.log(stack.shift()); // 1
console.log(stack); // []

// #3 stack class
class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

class Stack {
  constructor() {
    this.top = null;
    this.capacity = 0;
  }

  push(val) {
    const newNode = new Node(val);
    newNode.next = this.top;
    this.top = newNode;
    return ++this.capacity;
  }

  pop() {
    if (this.isEmpty()) {
      return 'Stack is empty';
    }
    const top = this.top;
    this.top = this.top.next;
    this.capacity--;
    return top.val;
  }

  peek() {
    if (this.isEmpty()) {
      return 'Stack is empty';
    }
    return this.top.val;
  }

  size() {
    return this.capacity;
  }

  isEmpty() {
    return this.capacity === 0 ? true : false;
  }

  print() {
    const arr = [];
    let curNode = this.top;
    while (curNode) {
      arr.push(curNode.val);
      curNode = curNode.next;
    }
    console.log(arr);
  }
}

// 테스트 코드
stack = new Stack();

// 1. Push 테스트
console.log('1. Push 테스트:');
stack.push('google');
stack.push('youtube');
stack.push('naver');
stack.print(); // [ 'naver', 'youtube', 'google' ]

// 2. Pop 테스트
console.log('2. Pop 테스트:');
console.log(stack.pop()); // 'naver'
console.log(stack.pop()); // 'youtube'
console.log(stack.pop()); // 'google'
console.log(stack.pop()); // 'Stack is empty'

// 3. Peek 테스트
console.log('3. Peek 테스트:');
stack.push('google');
stack.push('youtube');
console.log(stack.peek()); // 'youtube'
stack.print(); // [ 'youtube', 'google' ]

// 4. Size 테스트
console.log('4. Size 테스트:');
console.log(stack.size()); // 2

// 5. IsEmpty 테스트
console.log('5. IsEmpty 테스트:');
console.log(stack.isEmpty()); // false
stack.pop();
stack.pop();
console.log(stack.isEmpty()); // true

// 6. Print 테스트
console.log('6. Print 테스트:');
stack.push('google');
stack.push('youtube');
stack.print(); // [ 'youtube', 'google' ]

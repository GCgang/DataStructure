class HashTables {
  constructor(size = 13) {
    this.keyMap = new Array(size);
  }

  hash(key) {
    let total = 0;
    const WEIRD_PRIME = 31;
    for (let i = 0; i < Math.min(key.length, 100); ++i) {
      let char = key[i];
      let value = char.charCodeAt(0) - 96;
      total = (total * WEIRD_PRIME + value) % this.keyMap.length;
    }
    return total;
  }

  get(key) {
    const index = this.hash(key);
    const bucket = this.keyMap[index];
    if (bucket) {
      for (const [storedKey, storedValue] of bucket) {
        if (storedKey === key) {
          return storedValue;
        }
      }
    }
    return undefined;
  }
  set(key, value) {
    const index = this.hash(key);
    if (!this.keyMap[index]) {
      this.keyMap[index] = [];
    }
    this.keyMap[index].push([key, value]);
  }

  keys() {
    const keysArr = [];
    for (const bucket of this.keyMap) {
      if (bucket) {
        for (const [key] of bucket) {
          if (!this.keyMap.includes(key)) {
            keysArr.push(key);
          }
        }
      }
    }
    return keysArr;
  }
  values() {
    const valuesArr = [];
    for (const bucket of this.keyMap) {
      if (bucket) {
        for (const [, value] of bucket) {
          if (!valuesArr.includes(value)) {
            valuesArr.push(value);
          }
        }
      }
    }
    return valuesArr;
  }
}

const hashTable = new HashTables();
hashTable.set('yellow', '#FFFF00');
hashTable.set('brown', '#A52A2A');
hashTable.set('gray', '#808080');
hashTable.set('green', '#008000');
hashTable.set('pink', '#FFC0CB');
hashTable.set('cyan', '#00FFFF');
hashTable.set('salmon', '#FA8072');
hashTable.set('tomato', '#FF6347');
hashTable.set('orange', '#FFA500');
hashTable.set('blue', '#0000FF');
hashTable.set('Blue', '#0000FF');

console.log(hashTable);

console.log(hashTable.get('yellow')); // #FFFF00
console.log(hashTable.get('brown')); // #A52A2A
console.log(hashTable.get('salmon')); // #FA8072
console.log(hashTable.get('tomato')); // #FF6347

console.log(hashTable.get('fish')); // undefined
console.log(hashTable.get('apple')); // undefined

console.log(hashTable.keys());
console.log(hashTable.values());

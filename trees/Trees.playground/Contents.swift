import Foundation

// Морозов Алексей
// Задание 1. Хеширование методом Пирсона

class PearsonHashing {
    private var table: [UInt8] = {
        var table = [UInt8]()
        for i in 0...255 {
            table.append(UInt8(i))
        }
        
        return table.shuffled()
    }()
    
    
    func hash(data: String) -> UInt8 {
        var hash: UInt8 = UInt8(data.count % 256)
        for char in data {
            hash = table[Int(hash ^ char.asciiValue!)]
        }
        return hash
    }
}

let pearson = PearsonHashing()

let testMessage1 = "abc"
let testMessage2 = "Hello! "

print("Task 1")
print("Message #1: message = \(testMessage1) | Hash: \(pearson.hash(data: testMessage1))")
print("Message #2: message = \(testMessage2) | Hash: \(pearson.hash(data: testMessage2))")

print("Try to use hashing algorithm second time on same strings.")
print("Message #1: message = \(testMessage1) | Hash: \(pearson.hash(data: testMessage1))")
print("Message #2: message = \(testMessage2) | Hash: \(pearson.hash(data: testMessage2))")


// Задание 2. Двоичное дерево поиска

class BinaryNode<Element>: CustomStringConvertible {
    var value: Element
    var leftChild: BinaryNode?
    var rightChild: BinaryNode?
    
    init(value: Element) {
        self.value = value
    }
    
    // MARK: - Методы обхода
    
    // ЛКП — «левый–корень–правый»(симметричный обход, in-order)
    func traverseInOrder(visit: (Element) -> Void) {
        leftChild?.traverseInOrder(visit: visit)
        visit(value)
        rightChild?.traverseInOrder(visit: visit)
    }
    
    // КЛП — «корень–левый–правый»(обход в прямом порядке, pre-order)
    func traversePreOrder(visit: (Element) -> Void) {
        visit(value)
        leftChild?.traversePreOrder(visit: visit)
        rightChild?.traversePreOrder(visit: visit)
    }
    
    // ЛПК — «левый–правый–корень»(обход в обратном порядке, post-order)
    func traversePostOrder(visit: (Element) -> Void) {
        leftChild?.traversePostOrder(visit: visit)
        rightChild?.traversePostOrder(visit: visit)
        visit(value)
    }
    
    // MARK: - CustomStringConvertible
    
    var description: String {
        diagram(for: self)
    }
    
    func diagram(for node: BinaryNode?,
                 _ top: String = "",
                 _ root: String = "",
                 _ bottom: String = "") -> String {
        guard let node = node else {
            return root + "nil\n"
        }
        if node.leftChild == nil && node.rightChild == nil {
            return root + "\(node.value)\n"
        }
        return diagram(for: node.rightChild, top + " ", top + "┌──", top + "│ ")
            + root + "\(node.value)\n" +
            diagram(for: node.leftChild, bottom + "│ ", bottom + "└──", bottom + " ")
    }
}


struct BinarySearchTree<Element: Comparable>: CustomStringConvertible {
    private(set) var root: BinaryNode<Element>?
    
    init() {}
    
    // MARK: - CustomStringConvertible
    
    var description: String {
        guard let root = root else { return "Tree is empty." }
        return String(describing: root)
    }
    
    // MARK: - Операции
    
    mutating func insert(_ value: Element) {
        root = insert(from: root, value: value)
    }
    
    private func insert(from node: BinaryNode<Element>?, value: Element) -> BinaryNode<Element> {
        guard let node = node else {
            return BinaryNode(value: value)
        }
        
        if value < node.value {
            node.leftChild = insert(from: node.leftChild, value: value)
        } else {
            node.rightChild = insert(from: node.rightChild, value: value)
        }
        
        return node
    }
    
    public func contains(_ value: Element) -> Bool {
        guard let root = root else {
            return false
        }
        var found = false
        root.traverseInOrder {
            if $0 == value {
                found = true
            }
        }
        return found
    }
}

var tree: BinarySearchTree<Int> {
    var bst = BinarySearchTree<Int>()
    let numbersToInsert = [3, 1, 4, 0, 2, 5]
    numbersToInsert.forEach { (number) in
        bst.insert(number)
    }
    
    return bst
}

print("\nTask 2")
print(tree)
var numberToSearch: Int = 5
print("Does tree contains \(numberToSearch)? Answer: \(tree.contains(numberToSearch))")
numberToSearch = 7
print("Does tree contains \(numberToSearch)? Answer: \(tree.contains(numberToSearch))")

print("Traverse in-order:")
tree.root?.traverseInOrder {
    print($0)
}

print("Traverse pre-order:")
tree.root?.traversePreOrder {
    print($0)
}

print("Traverse post-order:")
tree.root?.traversePostOrder {
    print($0)
}

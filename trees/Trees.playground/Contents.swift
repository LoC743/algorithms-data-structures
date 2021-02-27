import Foundation

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

print("Message #1: message = \(testMessage1) | Hash: \(pearson.hash(data: testMessage1))")
print("Message #2: message = \(testMessage2) | Hash: \(pearson.hash(data: testMessage2))")

print("Try to use hashing algorithm second time on same strings.")
print("Message #1: message = \(testMessage1) | Hash: \(pearson.hash(data: testMessage1))")
print("Message #2: message = \(testMessage2) | Hash: \(pearson.hash(data: testMessage2))")

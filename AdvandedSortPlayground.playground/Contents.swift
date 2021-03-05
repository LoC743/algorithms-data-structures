import Foundation

func getRandomIntArray(with size: Int) -> [Int] {
    var array: [Int] = []
    for _ in 0..<size {
        array.append(Int.random(in: 0...100))
    }
    
    return array
}

let arrayToSort: [Int] = getRandomIntArray(with: 10)
print("Generated array: \(arrayToSort)")

func countingSort(array: [Int]) -> [Int] {
    guard let maxElement = array.max() else { return [] }
    var countArray = [Int](repeating: 0, count: Int(maxElement + 1))
    for element in array {
        countArray[element] += 1
    }
    for index in 1 ..< countArray.count {
        let sum = countArray[index] + countArray[index - 1]
        countArray[index] = sum
    }
    
    var sortedArray = [Int](repeating: 0, count: array.count)
    for index in stride(from: array.count - 1, through: 0, by: -1) {
        let element = array[index]
        countArray[element] -= 1
        sortedArray[countArray[element]] = element
    }
    
    return sortedArray
}

let countingSortResult = countingSort(array: arrayToSort)
print("Counting sort: \(countingSortResult)")

func quickSort(array: [Int]) -> [Int] {
    guard array.count > 1 else { return array }
    
    let pivot = array[array.count/2]
    let less = array.filter { $0 < pivot }
    let equal = array.filter { $0 == pivot }
    let greater = array.filter { $0 > pivot }
    
    return quickSort(array: less) + equal + quickSort(array: greater)
}

let quickSortResult = quickSort(array: arrayToSort)
print("Quick sort: \(quickSortResult)")

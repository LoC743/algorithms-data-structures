import Foundation

enum EdgeType {
    case directed
    case undirected
}

// MARK: - Vertex

struct Vertex<Element> {
    public let index: Int
    public let data: Element
}

extension Vertex: Hashable where Element: Hashable {}
extension Vertex: Equatable where Element: Equatable {}

extension Vertex: CustomStringConvertible {
    public var description: String {
        return "\(index): \(data)"
    }
}

// MARK: - Edge

struct Edge<Element> {
    let source: Vertex<Element>
    let destination: Vertex<Element>
    let weight: Double?
}

protocol Graph {
    associatedtype Element
    func createVertex(data: Element) -> Vertex<Element>
    func addDirectedEdge(from source: Vertex<Element>,
                         to destination: Vertex<Element>,
                         weight: Double?)
    func addUndirectedEdge(between source: Vertex<Element>,
                           and destination: Vertex<Element>,
                           weight: Double?)
    func add(_ edge: EdgeType, from source: Vertex<Element>,
             to destination: Vertex<Element>,
             weight: Double?)
    func edges(from source: Vertex<Element>) -> [Edge<Element>]
    func weight(from source: Vertex<Element>,
                to destination: Vertex<Element>) -> Double?
}

// MARK: - Adjacency Matrix

class AdjacencyMatrix<Element>: Graph {
    private var vertices: [Vertex<Element>] = []
    private var weights: [[Double?]] = []
    
    func createVertex(data: Element) -> Vertex<Element> {
        let vertex = Vertex(index: vertices.count, data: data)
        vertices.append(vertex)
        for i in 0..<weights.count {
            weights[i].append(nil)
        }
        let row = [Double?](repeating: nil, count: vertices.count)
        weights.append(row)
        
        return vertex
    }
    
    func addDirectedEdge(from source: Vertex<Element>,
                         to destination: Vertex<Element>,
                         weight: Double?) {
        weights[source.index][destination.index] = weight
    }
    
    func addUndirectedEdge(between source: Vertex<Element>,
                           and destination: Vertex<Element>,
                           weight: Double?) {
        addDirectedEdge(from: source, to: destination, weight: weight)
        addDirectedEdge(from: destination, to: source, weight: weight)
    }
    
    func add(_ edge: EdgeType,
             from source: Vertex<Element>,
             to destination: Vertex<Element>,
             weight: Double?) {
        switch edge {
        case .directed:
            addDirectedEdge(from: source, to: destination, weight: weight)
        case .undirected:
            addUndirectedEdge(between: source, and: destination, weight: weight)
        }
    }
    
    func edges(from source: Vertex<Element>) -> [Edge<Element>] {
        var edges: [Edge<Element>] = []
        for column in 0..<weights.count {
            if let weight = weights[source.index][column] {
                edges.append(Edge(source: source, destination: vertices[column], weight: weight))
            }
        }
        return edges
    }
    
    func weight(from source: Vertex<Element>, to destination: Vertex<Element>) -> Double? {
        return weights[source.index][destination.index]
    }
}

extension AdjacencyMatrix: CustomStringConvertible {
    var description: String {
        let verticesDescription = vertices.map { "\($0)" }
        var grid: [String] = []
        for i in 0..<weights.count {
            var row = ""
            for j in 0..<weights.count {
                if let value = weights[i][j] {
                    row += "  \(value)  "
                } else {
                    row += "  ø  "
                }
            }
            grid.append(row)
        }
        let edgesDescription = grid.joined(separator: "\n")
        
        return "\(verticesDescription)\n\n\(edgesDescription)"
    }
}

let graph = AdjacencyMatrix<String>()
let a = graph.createVertex(data: "A")
let b = graph.createVertex(data: "B")
let c = graph.createVertex(data: "C")
let d = graph.createVertex(data: "D")
let e = graph.createVertex(data: "E")

graph.add(.undirected, from: a, to: b, weight: 2)
graph.add(.undirected, from: a, to: c, weight: 5)
graph.add(.undirected, from: a, to: e, weight: 7)
graph.add(.undirected, from: b, to: c, weight: 1)
graph.add(.undirected, from: c, to: d, weight: 5)
graph.add(.undirected, from: c, to: e, weight: 1)
graph.add(.undirected, from: d, to: e, weight: 3)

print(graph)


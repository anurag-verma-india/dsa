# Garph 

Network of Nodes

- Edges: conneciton between any two nodes
- Vertex or vertices 

![Introduction](./01.png)


## Types of Graphs

### Based on direction of edges

1. Uni directional graphs (Directed Graphs)
![Unidirectional Graphs](./02-unidirectional.png)

2. Bi directional Graph (Undirected Graph)
![Directed Graphs](./03-directed.png)


### Based on weight of edges 

1. Weighted 
- Meaning of weight would depend on the situation
- Weight could be negative 
![Weighted Graph](./04-weighted.png)

2. Unweighted Graph
- No weight assiociated with edges 

### Combination of these 
- Undirected unweighted 
- Undirected weighted
- Directed weighted
- Directed unweighted

- Also Disconnected graphs 

![Disconnected Graphs](./05-disconnected-graphs.png)

## How to build a graph

### 1. Adjacency List 

- List -> Doubly Linked List

![List-data-structure-in-cpp](./06-list-data-structure-in-cpp.png)

- (Store neighbours ∀ V) Store Neighbours for all vertices, where V is vertices 

Note: we are going to use dynamic arrays for the implementation (we could use vectors or static arrays)

![Adjacency-list-example](./07-adjacency-list-example.png)

>> Undirected Graphs

![undirected-graph](./08-undirected-graph.png)

- [undirected-unweighted-graph.cpp](./09-undirected-unweighted-graph.cpp)



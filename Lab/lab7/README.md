Lab 7: Graphs
-------------

In this lab you will learn to construct a graph from an input file. The tasks for this lab are as follows.

<ol>
  <li>Read a graph from a file. </li>
  <li>Construct the corresponding graph in memory. The graph must be represented by adjacent lists. You may use STL list or vector class where needed. </li>
  <li>Run Breadth First Search (BFS) on the graph, annotating each node with its level, i.e. the minimum number of hops the node is from the start vertex. </li>
  <li>Output the annotated graph in .dot format. </li>
  <li>Verify your results via Graphviz website. </li>
  <li>Overload your Graph constructor to make use of an STL map during construction. Read more about the map class here. </li>
  <li>Repeat 4 & 5 with the graph generated in 6. </li>
</ol>

Input File Format
-----------------

The first line gives the number of nodes N and a number of edges M (both positive integers). You can assume the following:

* N is at most MaxN = 50
* M is at most maxM = 200.
* The next N lines contain node labels, one per line. Each node's label is a string of at most maxNameLength = 15 characters (spaces not allowed). NOTE: The first node in the input file is assumed to be the start vertex of the graph.
* The next M lines contain edges, where (u,v) is described by a pair of labels, the label of u followed by the label of v, separated by at least one space.

Graph Structure
---------------

> Graph.H - Graph class.
  >> vector vertices - A vector containing all of the vertices in the graph. The start vertex is in the first node in the adjacency list.
  >> void build_graph(ifstream& ifs)- Reads the graph input file and instantiates a graph object. Call from within an overloaded Graph constructor which gets passed in an ifstream object (see parameter). Call this overloaded Graph constructor from within your main function.
  >> void output_graph() - Outputs graph object to a graph.dot file.
  >> void bfs()- Breadth First Search. Via a BFS traversal, this function should assign each individual vertex's distance to the number of hops that the vertex is from the start vertex.
> Vertex.H - Vertex class. 
  >> string label - Individual vertex's label.
  >> int distance - Distance the vertex is from the start vertex.
  >> list<int> neighbors - An STL list of the vertices adjacent to the vertex. The integer value is the neighboring vertex's position in the graph object's vector vertices.
  >> vector<int> neighbors - (Optional) To be used instead of STL list.

BFS
---
Breadth First Search is a search algorithm for graphs. BFS can be used to traverse a connected graph. BFS starts at an initial node and visits nodes at successive levels (number of hops) away from the initial source node. You are required to use an STL queue in your BFS implementation.

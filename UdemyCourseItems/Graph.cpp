#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string>> adjList;

public:
    void printGraph()
    {
        unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
        while (kvPair != adjList.end())
        {
            cout << kvPair->first << ": [ "; // this prints out the vertex
            unordered_set<string>::iterator edge = kvPair->second.begin();
            while (edge != kvPair->second.end())
            {
                cout << edge->data() << " "; // this prints out edges
                edge++;
            }
            cout << "]" << endl;
            kvPair++;
        }
    }

    // Add a new vertex to the graph
    bool addVertex(string vertex)
    {
        // Check if the vertex already exists in the graph
        if (adjList.count(vertex) == 0)
        {
            // Add the new vertex to the adjacency list with an empty vector as its value
            adjList[vertex];
            return true; // Return true to indicate success
        }

        // If the vertex already exists in the graph, do not add it again and return false
        return false;
    }

    // Add an undirected edge between two vertices in the graph
    bool addEdge(string vertex1, string vertex2)
    {
        // Check if both vertices exist in the graph
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            // Insert vertex2 into the vector of adjacent vertices for vertex1
            adjList.at(vertex1).insert(vertex2);

            // Insert vertex1 into the vector of adjacent vertices for vertex2
            adjList.at(vertex2).insert(vertex1);

            // Return true to indicate success
            return true;
        }

        // If either vertex does not exist in the graph, do not add the edge and return false
        return false;
    }

    // Remove an undirected edge between two vertices in the graph
    bool removeEdge(string vertex1, string vertex2)
    {
        // Check if both vertices exist in the graph
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            // Erase vertex2 from the vector of adjacent vertices for vertex1
            adjList.at(vertex1).erase(vertex2);

            // Erase vertex1 from the vector of adjacent vertices for vertex2
            adjList.at(vertex2).erase(vertex1);

            // Return true to indicate success
            return true;
        }

        // If either vertex does not exist in the graph, do not remove the edge and return false
        return false;
    }

    // Remove a vertex and its edges from the graph
    bool removeVertex(string vertex)
    {
        // Check if the vertex exists in the graph
        if (adjList.count(vertex) == 0)
            return false;

        // Remove the vertex from the adjacency lists of all adjacent vertices
        for (auto otherVertex : adjList.at(vertex))
        {
            adjList.at(otherVertex).erase(vertex);
        }

        // Remove the vertex and its adjacency list from the graph
        adjList.erase(vertex);

        // Return true to indicate success
        return true;
    }

    // This function checks if two vertices are connected by an edge
    bool areConnected(string vertex1, string vertex2)
    {
        // Check if either of the vertices does not exist in the graph
        // If either vertex is not found, return false
        if (adjList.count(vertex1) == 0 || adjList.count(vertex2) == 0)
            return false;

        // Check if vertex2 is in the adjacency list of vertex1
        // If it is, return true; otherwise, return false
        return adjList.at(vertex1).count(vertex2) > 0;
    }
};

int main()
{
    Graph *myGraph = new Graph();

    // Add vertices to the graph
    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addVertex("D");

    cout << "Graph after adding vertices:\n";
    myGraph->printGraph();

    /*
        EXPECTED OUTPUT:
        ----------------
        Graph after adding vertices:
        D: [ ]
        C: [ ]
        B: [ ]
        A: [ ]
    */

    // Add edges between vertices
    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("B", "D");

    cout << "\nGraph after adding edges:\n";
    myGraph->printGraph();

    /*
        EXPECTED OUTPUT:
        ----------------
        Graph after adding edges:
        D: [ B ]
        C: [ A ]
        B: [ A D ]
        A: [ B C ]
    */

    // Check if two vertices are connected
    cout << "\nAre A and B connected? " << (myGraph->areConnected("A", "B") ? "Yes" : "No") << endl;
    cout << "Are A and D connected? " << (myGraph->areConnected("A", "D") ? "Yes" : "No") << endl;

    /*
        EXPECTED OUTPUT:
        ----------------
        Are A and B connected? Yes
        Are A and D connected? No
    */

    // Remove an edge
    myGraph->removeEdge("A", "B");

    cout << "\nGraph after removing edge between A and B:\n";
    myGraph->printGraph();

    /*
        EXPECTED OUTPUT:
        ----------------
        Graph after removing edge between A and B:
        D: [ B ]
        C: [ A ]
        B: [ D ]
        A: [ C ]
    */

    // Remove a vertex
    myGraph->removeVertex("C");

    cout << "\nGraph after removing vertex C:\n";
    myGraph->printGraph();

    /*
        EXPECTED OUTPUT:
        ----------------
        Graph after removing vertex C:
        D: [ B ]
        B: [ D ]
        A: [ ]
    */

    // Cleanup
    delete myGraph;

    return 0;
}

// jdh CS224 Spring 2023

import java.util.List;
import java.util.ArrayList;

public class Graph {
  List<Node> nodes;

  public Graph() {
    this.nodes = new ArrayList<Node>();
  }

  public void addNode(Node node) {
    // make sure this node does not already exist
    for (Node n: this.nodes) {
      if (n == node) {
        System.out.println("ERROR: node " + n + " is already in graph");
        return;
      }
    }
    this.nodes.add(node);
  } // addNode()

  public void addEdge(Node n1, Node n2, int weight) {
    // outgoing edge
    int idx1 = this.nodes.indexOf(n1);
    if (idx1 < 0) {
      System.out.println("ERROR: node " + n1.name + " not found in graph");
      return;
    }

    int idx2 = this.nodes.indexOf(n2);
    if (idx2 < 0) {
      System.out.println("ERROR: node " + n2.name + " not found in graph");
      return;
    }

    n1.addEdge(n2, weight);
  } // addEdge()

  public void print() {
    for (Node n: this.nodes) {
      System.out.print("Node " + n.name + " out:");
      for (Edge e: n.adjlistOut)
        System.out.print(" " + e);
      System.out.println();
      System.out.print("Node " + n.name + " in:");
      for (Edge e: n.adjlistIn)
        System.out.print(" " + e);
      System.out.println();
    }
  } // print()

  //----------------------------------------------------------------

  public Object[] BellmanFord(Node t) {
    // implement this
  } // BellmanFord()

  //----------------------------------------------------------------

  public Object[] BellmanFordPush(Node t) {
    // implement this
  } // BellmanFord()

} // class Graph

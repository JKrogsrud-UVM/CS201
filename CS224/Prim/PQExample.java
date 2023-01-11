// jdh CS224 Spring 2023

import java.util.PriorityQueue;

public class PQExample {
  public static void main(String args[]) {
    PQtest();
  }

  public static void PQtest() {
    PriorityQueue<Thing> PQ;
    PQ = new PriorityQueue<Thing>(20);

    // each entry in the queue is a Thing;
    // they'll be put in the queue in priority order
    Thing t1 = new Thing("Audi", 5);
    PQ.add(t1);
    Thing t2 = new Thing("Civic", 10);
    PQ.add(t2);
    Thing t3 = new Thing("Outback", 2);
    PQ.add(t3);
    Thing t4 = new Thing("Tesla", 12);
    PQ.add(t4);

    while (PQ.size() > 0) {
      Thing t = PQ.poll();
      System.out.println("popped this thing: " + t);
    }

    System.out.println();

    // now same experiment, but this time also changing
    // the priorities of items in the queue ("updating keys")
    PQ.add(t1);
    PQ.add(t2);
    PQ.add(t3);
    PQ.add(t4);

    t2.updatePriority(1);

    // must explicitly call updatePQ()
    updatePQ(PQ);

    while (PQ.size() > 0) {
      Thing t = PQ.poll();
      System.out.println("popped this thing: " + t);
    }
  }

  //-----------------------------------------------------
  // this is a static because it's in Main

  public static void updatePQ(PriorityQueue<Thing> pq) {
    Object arr[] = pq.toArray();
    pq.clear();
    for (int i=0; i<arr.length; ++i) {
      Thing t = (Thing) arr[i];
      pq.add(t);
    }
  }
}

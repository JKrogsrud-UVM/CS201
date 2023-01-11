// jdh Spring 2023 CS224

import java.util.List;
import java.util.ArrayList;

public class PointCollection {
  List<Point> points;
  Point y_arr[];
  int origN;

  //--------------------------------------------------------------

  public PointCollection() {
    points = new ArrayList<Point>();
  }

  //--------------------------------------------------------------

  void addPoint(Point p) {
    points.add(p);
  }

  //--------------------------------------------------------------

  PointPair closestPairRec(List<Point> Px, List<Point> Py) {
    // implement this function
  } // closestPairRec()

  //--------------------------------------------------------------

  PointPair closestPair() {
    // implement this function
  } // closetPair()

  //--------------------------------------------------------------

  PointPair bruteForce() {
    // implement this function
  } // bruteForce()
}

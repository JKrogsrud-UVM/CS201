// jdh CS224 Spring 2023

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class BruteForce {
  public static void main(String args[]) {
    testOne();
//  testTwo();
  }

  //---------------------------------------------------
  // An example, with four friends: Jack, Mary, Henry, and Elizabeth
  // - Jack has a conflict with Mary and Elizabeth
  // - Mary has conflict with Henry and Elizabeth
  // - Henry has a conflict with Elizabeth
  // There is a single subset of size = 2 having no conflicts:
  // Jack and Henry

  public static void testOne() {
    Friend jack = new Friend("Jack");
    Friend mary = new Friend("Mary");
    Friend henry = new Friend("Henry");
    Friend elizabeth = new Friend("Elizabeth");
    Friend[] allFriends = {jack, mary, henry, elizabeth};

    Friend[] jack_conflicts = {mary, elizabeth};
    jack.setConflicts(new ArrayList<Friend>(Arrays.asList(jack_conflicts)));
    Friend[] mary_conflicts = {henry, elizabeth};
    mary.setConflicts(new ArrayList<Friend>(Arrays.asList(mary_conflicts)));
    Friend[] henry_conflicts = {elizabeth};
    henry.setConflicts(new ArrayList<Friend>(Arrays.asList(henry_conflicts)));

    List<Friend> best = optimize(allFriends);
    System.out.println("largest independent set:");
    for (Friend f: best)
      System.out.print(f + " ");
    System.out.println();
  }

  //---------------------------------------------------

  public static void testTwo() {
    // implement this

    List<Friend> best = optimize(allFriends);
    System.out.println("largest independent set:");
    for (Friend f: best)
      System.out.print(f + " ");
    System.out.println();
  }

  //----------------------------------------------------------

  public static List<Friend> optimize(Friend allFriends[]) {
    // implement this
  } // optimize()
}

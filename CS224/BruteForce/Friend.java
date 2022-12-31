// jdh CS224 Spring 2023

import java.util.List;
import java.util.ArrayList;

public class Friend {
  String name;
  List<Friend> conflicts;

  public Friend(String name) {
    this.name = name;
    this.conflicts = new ArrayList<Friend>();
  }

  public String toString() {
    return this.name;
  }

  public void setConflicts(List<Friend> conflicts) {
    for (Friend friend: conflicts)
      this.conflicts.add(friend);
  }

  public boolean hasConflictWith(Friend friend) {
    int idx = this.conflicts.indexOf(friend);
    if (idx >= 0)
      return true;
    else
      return false;
  }
}

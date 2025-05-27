import java.util.*;
class Node{
    HashMap<Character,Node>child;
    Boolean isTerminal;
    public Node(){
        child = new HashMap<>();
        isTerminal = false;
    }
}
class Trie {
    Node root;
    public Trie() {
        root = new Node();
    }
  
    public void insert(String[] strs) {
        for (String str : strs) {
            Node cur = this.root;
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                cur.child.putIfAbsent(c, new Node());
                cur = cur.child.get(c);
                if (i == str.length() - 1) {
                    cur.isTerminal = true;
                }
            }
        }
    }

    public Boolean search(Node node,String[] strs) {
      for (String str : strs) {
          int cnt=0;
          Node cur = node;
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                cur = cur.child.get(c);
                if (cur.isTerminal && cnt<str.length()-1) {
                    return false;
                }
                cnt++;
            }
        }
        return true;
    }
}
class Solution {
    public boolean solution(String[] phone_book) {
        Trie trie = new Trie();
        trie.insert(phone_book);
        boolean answer = trie.search(trie.root,phone_book);
        return answer;
    }
}

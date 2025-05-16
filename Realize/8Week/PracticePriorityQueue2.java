// Practice 1
// 자바 기본 PriorityQueue 응용
// 나이 순으로 오름차순 또는 내림차순 출력


import java.util.PriorityQueue;

class Person implements Comparable<Person>{
    String name;
    int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Person o) {
        //1 : 변경 안 함 (새롭게 들어온 애가 우선순위가 더 높지 않다고 생각)
        // -1 : 변경

        //새롭게 추가하는 데이터가 더 작을 때 변경 (오름차순)
        //return this.age>=o.age?1:-1; //(this.age가 방금 들어온 애)
        // 새롭게 추가하는 데이터가 더 클 때 변경 ( 내림차순)
        return this.age>=o.age?-1:1;
    }
}

public class Practice1 {
    public static void solution(String[] name, int[] age) {
        PriorityQueue<Person>pq = new PriorityQueue<Person>();

        for (int i = 0; i < name.length; i++) {
            pq.offer(new Person(name[i],age[i]));
        }
        System.out.println("== 실제 출력 순서 ==");
        while (!pq.isEmpty()){
            Person p = pq.poll();
            System.out.println(p.name + p.age);
        }
    }

    public static void main(String[] args) {
        String[] name = {"A", "B", "C", "D", "E"};
        int[] age = {30, 20, 45, 62, 35};

        solution(name, age);
    }
}

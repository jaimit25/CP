
import java.util.*;

public class CollectionFramework {
    public static void main(String[] args) {
        System.out.println("Welcome to code java collection framework");

       /*
       creating collection

       1)Type Safe- same type of elements(objects) are added to collection


       2)Un Type safe- different types of elements can be added to collection

        */

        //Type safe collection
        ArrayList<String> names = new ArrayList<String>();
        names.add("Durgesh");
        names.add("Sitara");
        names.add("Roshni");
        names.add("Vandna");
        names.add("Vandna");
        System.out.println(names);

        //get
//        System.out.println(names.get(0));
//        System.out.println(names.get(1));


        //un type safe
//        LinkedList list = new LinkedList();
//        list.add("Sachin");
//        list.add(101);
//        list.add(625.5124);
//        list.add(true);
//        System.out.println(list);

        //remove
        names.remove("Roshni");

        System.out.println(names);

        //size

        System.out.println("SIZE = " + names.size());

        //check item is there or not
        // Type ka equals method call karta hai checking karne ke lie
        //Student
        System.out.println(names.contains("Durgesh Kumar"));

        //check for empy
        System.out.println(names.isEmpty());

        //setting value..
        //names.set(1,"Ram");
        names.add(1, "Ram");

        System.out.println(names);

        //remove all elements
//        names.clear();

        System.out.println(names);

        Vector<String> vector = new Vector<>();
        vector.addAll(names);

        System.out.println("VECTOR " + vector);

        System.out.println("_____________________________________");

        HashSet<Double> nms = new HashSet<>();
        nms.add(14.14);
        nms.add(34.12354);
        nms.add((2354.235));
        nms.add(99.3);
        nms.add(99.3);
        nms.add(5.3);
        System.out.println(nms);

        TreeSet<Double> tset = new TreeSet<>();
        tset.addAll(nms);
        System.out.println(tset);




	
	// TraverseExample

	ArrayList<String> names = new ArrayList<String>();
        names.add("Durgesh");
        names.add("Sitara");
        names.add("Roshni");
        names.add("Vandna");
        names.add("Vandna");
        names.add("ABC");

        //for each loop:
        for(String str:names)
        {
            System.out.print(str +"\t"+str.length()+"\t");
            StringBuffer br=new StringBuffer(str);
            System.out.println(br.reverse());
        }
        System.out.println("________________________");

        //traversing using ITERATOR: Forward traversing
        Iterator<String> itr = names.iterator();

        while(itr.hasNext())
        {
            String next = itr.next();
            System.out.println(next);
        }
        System.out.println("+++++++++++++++++++++++");

        //backward traversal of collection LISTITERATOR
        ListIterator<String> litr = names.listIterator(names.size());
        while(litr.hasPrevious())
        {
            String previous = litr.previous();
            System.out.println(previous);
        }

        //Enumeration
        System.out.println("++++++++FOR EACH METHOD+++++++++++++");
        //for each method

        names.forEach(str->{
            System.out.println(str);
        });

        System.out.println("SORTING OF ELEMENTS");
        TreeSet<String> set=new TreeSet<>();
        set.addAll(names);
        set.forEach(e->{
            System.out.println(e);
        });

//        Comparable
//        Comparator


	//HASHMAP

 HashMap<String,Integer>  courses=new HashMap<>();

        //adding elements
        courses.put("Core Java",4000);
        courses.put("Basic Python",3500);
        courses.put("Spring",8000);
        courses.put("Android",4000);
        courses.put("Android",6000);
        courses.put("PHP",2414);


        System.out.println(courses);

//        courses.forEach((e1,e2)->{
//            System.out.println(e1+"=>"+e2);
//        });

        courses.forEach((key,value)->{
            System.out.print(key);
            System.out.print("=>");
            System.out.println(value);
            System.out.println();
        });

        //entry set
        //key set

        System.out.println(courses.get("Core Java"));




    }
}
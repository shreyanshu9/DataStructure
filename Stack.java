package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.LinkedList;

public class Stack {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static LinkedList list = new LinkedList();
	
	static void push(LinkedList linkedList, String obj) {
		linkedList.addLast(obj);
	}
	
	static String pop(LinkedList linkedList) {
		String obj = (String) linkedList.getLast();
		linkedList.removeLast();
		return obj;
	}
	
	static String top(LinkedList linkedList) {
		return linkedList.getLast().toString();
	}
	
	static void display(LinkedList linkedList) {
		Iterator itr = linkedList.iterator();
		while(itr.hasNext()) {
			System.out.print(itr.next() + " ");
		}
		System.out.println();
	}
	
	static int linkedMenu() throws NumberFormatException, IOException {
	    int choice;
	    String n;
	    System.out.println("==Stack Menu==");
	    System.out.println("1.Push");
	    System.out.println("2.Pop");
	    System.out.println("3.Display");
	    System.out.println("4.Exit");
	    System.out.println("Enter your choice : ");
	    choice = Integer.parseInt(br.readLine());
	    switch(choice) {
	        case 1: System.out.println("\nEnter Data : ");
	        		n = br.readLine();
	        		push(list, n);
	                break;

	        case 2: pop(list);
	                break;

	        case 3: display(list);
	                break;

	        case 4: System.out.println("\nExit...");
	        	    return 4;
	    }
	    return choice;
	}


	public static void main(String[] args) throws NumberFormatException, IOException{
		int choice;
	    do {
	        choice = linkedMenu();
	    } while (choice != 4);	
	}
}
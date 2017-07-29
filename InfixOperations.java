package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

import dataStructure.Stack;

public class InfixConversion {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static LinkedList list = new LinkedList();
	
	static boolean isOperator(String exp) {
	    if(exp.equals("*") || exp.equals("/") || exp.equals("+") || exp.equals("-"))  {
	        return true;
	    }
	    return false;
	}
	
	static int getResult(String exp, int opr1, int opr2) {
	    int result = 0;
	    if(exp.equals("*")) {
	        result = opr1 * opr2;
	    } else if (exp.equals("/")) {
	        result = opr1 / opr2;
	    } else if (exp.equals("+")) {
	        result = opr1 + opr2;
	    } else if (exp.equals("-")) {
	        result = opr1 - opr2;
	    }
	    return result;
	}
	
	static void evaluate(int choice) throws IOException {
		 String exp,result;
		 int opr1, opr2, res;
		 System.out.println("Enter expression : ");
		 exp = br.readLine();
		 if (choice == 2) {
			 StringBuffer s = new StringBuffer(exp);
			 exp = s.reverse().toString();
		 }
		 StringTokenizer st = new StringTokenizer(exp);

		 while(st.hasMoreElements()) {
		    exp = st.nextToken();
		    if(isOperator(exp)) {
		    	if (choice == 2) {
		    		opr1 = Integer.parseInt(Stack.pop(list));
			        opr2 = Integer.parseInt(Stack.pop(list));
		    	} else {
		    		opr2 = Integer.parseInt(Stack.pop(list));
			        opr1 = Integer.parseInt(Stack.pop(list));
		    	}
		        res = getResult(exp, opr1, opr2);
		        result = String.valueOf(res);
		        Stack.push(list, result);
		    } else {
		        Stack.push(list, exp);
		    }
		 }
		 System.out.println("Result : " + Stack.pop(list));
		}
	
	static void postConversion() throws IOException {
		String exp, result = "";
		System.out.println("Enter Infix Expression : ");
		exp = "( " + br.readLine() + " )";
		StringTokenizer expToken = new StringTokenizer(exp);
		while (expToken.hasMoreElements()) {
			exp = expToken.nextToken();
			if (exp.equals("(")) {
				Stack.push(list, exp);
			} else if (exp.equals(")")) {
				exp = Stack.pop(list);
				while (!exp.equals("(")) {
					result = result + " "  + exp;
					exp = Stack.pop(list);
				}
			} else if (isNumber(exp)) {
				result = result + " " + exp;
			} else if (isOperator(exp)) {
				if (isOperator(Stack.top(list)) && checkPriority(Stack.top(list), exp)) {
						result = result + " " + Stack.pop(list);
				}
				Stack.push(list, exp);
			}
		}
		System.out.println("\n Postfix : " + result);
	}
	
	private static int getValue(String exp) {
		if (exp.equals("*") || exp.equals("/")) {
			return 2;
		} else if (exp.equals("+") || exp.equals("-")) {
			return 1;
		}
		return 0;
	}
	
	private static boolean checkPriority(String top, String exp) {
		int valueTop, valueExp;
		valueTop = getValue(top);
		valueExp = getValue(exp);
		if (valueTop >= valueExp) {
			return true;
		}
		return false;
	}

	private static boolean isNumber(String exp) {
		if (exp.matches("^[0-9]+$")) {
			return true;
		}
		return false;
	}

	static int entryDisplay() throws NumberFormatException, IOException {
	    int choice;
	    System.out.println("===Infix Menu===");
	    System.out.println("1. Evaluation of Postfix");
	    System.out.println("2. Evaluation of Prefix");
	    System.out.println("3. Conversion to Postfix");
	    System.out.println("4. Exit");
	    System.out.println("Enter Your Choice : ");
	    choice = Integer.parseInt(br.readLine());
	    return choice;
	}

	static void displayAction(int choice) throws IOException {
	    switch(choice) {
	        case 1: evaluate(1);
	                break;

	        case 2: evaluate(2);
	                break;
	                
	        case 3: postConversion();
	        		break;

	        case 4: return;
	    }
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int choice;
	    do {
	        choice = entryDisplay();
	        displayAction(choice);
	        list.clear();
	    } while (choice != 4);
	}

}
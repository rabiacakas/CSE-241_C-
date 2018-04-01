/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gtusetmap;

import java.security.InvalidParameterException;
import javafx.util.Pair;
/**
 * Rabia ÇAKAS 141044042 HW07
 */

/**
 *
 * @author rabia
 */
public class GTUSetMap<T> extends GTUSet<T>{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        GTUSet<Integer> newSet = new GTUSet();
        GTUSet<Integer> otherSet = new GTUSet();
        GTUMap<Integer,String> mapDeneme= new GTUMap();
        GTUMap<Integer,String> mapDeneme2= new GTUMap();
        GTUSet<Integer>.GTUIterator<Integer> iterObject;
        iterObject = newSet.new GTUIterator<Integer>();
        
        try{
            newSet.insert(50);
            newSet.insert(10);
            newSet.insert(20);
            newSet.insert(40);
            newSet.insert(80);
            newSet.insert(90);
            System.out.print("In newSet content: ");
            newSet.printContent();
            System.out.println("begin()+1: "+ newSet.begin().next());
            System.out.println("end()-1: "+ newSet.end().previous());
            System.out.println("find(20)+next: "+ newSet.find(20).next());
            
            newSet.erase(10);
            System.out.print("In newSet content after 10 erase: ");
            newSet.printContent();
            
            otherSet.insert(50);
            otherSet.insert(40);
            System.out.print("In otherSet content:");
            otherSet.printContent();
            newSet.setIntersection(otherSet);
            
            Pair<Integer, String> a = new Pair(1,"rabia");
            Pair<Integer, String> b = new Pair(2,"c++");
            Pair<Integer, String> c = new Pair(3,"2017");
            mapDeneme.insert(a);
            mapDeneme.insert(b);
            mapDeneme.insert(c);
            System.out.print("In mapDeneme content: ");
            mapDeneme.printContent();
            
            mapDeneme2.insert(a);
            mapDeneme2.insert(b);
            System.out.print("In mapDeneme2 content: ");
            mapDeneme2.printContent();
            
            mapDeneme.erase(a);
            System.out.println("In mapDeneme content after pair a erase: ");
            mapDeneme.printContent();
            
            System.out.print("In mapDeneme pair b value for at() function: ");
            mapDeneme.at(b.getKey());
            
            System.out.println("begin()+1: "+ mapDeneme.begin().next());
            System.out.println("end()-1: "+ mapDeneme.end().previous());
            System.out.println("find(a)+next: "+ mapDeneme.find(a).next());
            
            mapDeneme.setIntersection(mapDeneme2);       
            
        }
        catch(InvalidParameterException e){
	  System.err.print("Invalid argument: "+ e.getMessage());
  	}
        catch(NullPointerException e){
            System.out.print(e);
        }
    }
    
}

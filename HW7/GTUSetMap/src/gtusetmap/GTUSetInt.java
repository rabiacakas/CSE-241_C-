/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gtusetmap;

//import gtusetmap.GTUSet.GTUIterator;
import java.security.InvalidParameterException;

/**
 *
 * @author rabia
 * @param <T> for template element in interface
 */
public interface GTUSetInt<T> {

    public interface GTUIteratorAbs<T>{
        public boolean hasNext();
        public boolean hasPrevious();
        public T next();
        public T previous();
    }
    
    public boolean empty();
    public int size();
    public int max_size();
    public void insert(Object element) throws InvalidParameterException;
    public GTUSet<T> setIntersection(GTUSet<T> other);
    public void erase(Object element);
    public void clear();
    public GTUSet<T>.GTUIterator<T> find(T value);
    public int count(Object value);
    public GTUSet<T>.GTUIterator<T> begin();
    public GTUSet<T>.GTUIterator<T> end();
    public boolean itContains(T value);
    public void printContent();
}

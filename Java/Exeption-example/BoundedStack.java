import java.util.EmptyStackException;

/** BoundedStack
 *
 *  An implementation of a bounded stack of integers data structure
 *
 *  @invariant 0 <= getHeight() && getHeight() <= getMaxHeight()
 *  @invariant isEmpty() <==> getHeight() == 0
 *  @invariant isFull() <==> getHeight() == getMaxHeight()
 */
public class BoundedStack {
    private int[] values;
    private int height;
    
    /** Create an empty bounded stack of max height maxHeight.
        @param maxHeight the maximal height of the stack
        
        @requires maxHeight >= 0
        @ensures isEmpty()
        @ensures getMaxHeight() == maxHeight
    */
    public BoundedStack(int maxHeight) {
        values = new int[maxHeight];
        height = 0;
    }
    /** Return the height of the stack
        @return the height of the stack
        @pure
    */
    public int getHeight() {
        return height;
    }
    /** Return the maximal height of the stack
        @return the maximal height of the stack
        @pure
    */
    public int getMaxHeight() {
        return values.length;
    }
    /** push the element e at the top of the stack
        @param e the element to push at the top

        @requires !isFull()
        @ensures getHeight() == \old(getHeight()) + 1
        @ensures peek() == e
    */
    public void push(int e) {
        if(isFull()){
            throw new FullStackException("Your stack is already full...!!!");
        }
        values[height] = e;
        ++height;
    }
    /** pop an element from the stack
        @return the element which was at the top of the stack.

        @requires !isEmpty()
        @ensures getHeight() == \old(getHeight()) - 1
        @ensures \result == \old(peek())
    */
    public int pop() {
        if(isEmpty()){
            throw new EmptyStackException();
        }
        --height;
        return values[height];
    }
    /** return the top element of the stack
        @return the element which is at the top of the stack.
        @requires !isEmpty()
        @pure
    */
    public int peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return values[height - 1];
    }
    /** return true if and only if the stack is empty
        @return true if and only if the stack is empty
        @pure
    */
    public boolean isEmpty() {
        return height == 0;
    }
    /** return true if and only if the stack is full
        @return true if and only if the stack is full
        @pure
    */
    public boolean isFull() {
        return height == getMaxHeight();
    }

    /** Custom exception for full stack */
    public static class FullStackException extends RuntimeException {
        public FullStackException(String message) {
            super(message);
        }
    }
}

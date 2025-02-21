// Step 4: Test the class in a main method
public class Main {
    public static void main(String[] args) {
        try {
            // Test the constructor and input method
            BoundedInteger bi1 = BoundedInteger.input();
            BoundedInteger bi2 = BoundedInteger.input();

            // Print values
            System.out.println("First BoundedInteger: " + bi1.getValue());
            System.out.println("Second BoundedInteger: " + bi2.getValue());

            // Test addition
            try {
                BoundedInteger sum = bi1.add(bi2);
                System.out.println("Sum: " + sum.getValue());
            } catch (IntegerOutOfBounds e) {
                System.err.println("Addition error: " + e.getMessage());
            }

            // Test division
            try {
                BoundedInteger quotient = bi1.divide(bi2);
                System.out.println("Quotient: " + quotient.getValue());
            } catch (ArithmeticException e) {
                System.err.println("Division error: " + e.getMessage());
            }
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}


// Step 2: Define the BoundedInteger class
class BoundedInteger {
    private static final int MIN_BOUND = -10000;
    private static final int MAX_BOUND = 10000;
    private final int value;

    // Constructor with bounds checking
    public BoundedInteger(int value) {
        if (value < MIN_BOUND || value > MAX_BOUND) {
            throw new IntegerOutOfBounds("Value " + value + " is out of bounds (" + MIN_BOUND + ", " + MAX_BOUND + ").");
        }
        this.value = value;
    }

    // Getter for the value
    public int getValue() {
        return value;
    }

    // Step 3: Static input method
    public static BoundedInteger input() {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        System.out.print("Enter an integer between -10000 and 10000: ");

        try {
            int userInput = Integer.parseInt(scanner.nextLine());
            return new BoundedInteger(userInput);
        } catch (NumberFormatException e) {
            throw new NumberFormatException("Invalid input. Please enter a valid integer.");
        }
    }

    // Step 5: Add method
    public BoundedInteger add(BoundedInteger other) {
        int result = this.value + other.value;
        if (result < MIN_BOUND || result > MAX_BOUND) {
            throw new IntegerOutOfBounds("Result " + result + " is out of bounds (" + MIN_BOUND + ", " + MAX_BOUND + ").");
        }
        return new BoundedInteger(result);
    }

    // Step 6: Division method
    public BoundedInteger divide(BoundedInteger other) {
        if (other.value == 0) {
            throw new ArithmeticException("Division by zero is not allowed.");
        }
        // Division will not cause bounds issues since the result of division always narrows the range
        return new BoundedInteger(this.value / other.value);
    }
}


public class Dolphin extends Mammal implements UnderWater, Echolocation {
    @Override
    public void moveUnderWater() {
        System.out.println("The dolphin is swimming underwater.");
    }

    @Override
    public void sendSound() {
        System.out.println("The dolphin sends sound.");
    }

    @Override
    public void receiveSound() {
        System.out.println("The dolphin receives sound.");
    }
}

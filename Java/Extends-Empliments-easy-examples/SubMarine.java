public class SubMarine implements Echolocation,UnderWater{
    @Override 
    public void sendSound(){
        System.out.println("Submarine sends sound");
    }

    @Override
    public void receiveSound(){
        System.out.println("Submarine receiving sounds");
    }

    @Override
    public void moveUnderWater(){
        System.out.println("Submarine moves under water");
    }
}

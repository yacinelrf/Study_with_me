public class Sea {
    public static void main(String[] args) {
        UnderWater[] marins = new UnderWater[4];

        marins[0] = new SubMarine();
        marins[1] = new Merlu();
        marins[2] = new Dolphin();
        marins[3] = new SeaCat();

        for (UnderWater x : marins) {
            x.moveUnderWater();

        }
    }
}

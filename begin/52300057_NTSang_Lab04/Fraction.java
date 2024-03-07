public class Fraction {
    private int numerator;
    private int denominator;
    Fraction(){}
    Fraction(Fraction fraction){
        this.numerator = fraction.numerator;
        this.denominator = fraction.denominator;
    }
    Fraction(int num, int den){
        denominator = den;
        numerator = num;
    }
    public Fraction add(Fraction f1,Fraction f2){
        return new Fraction(f1.numerator + f2.numerator, f1.denominator + f2.denominator);
    }
    public Fraction sub(Fraction f1,Fraction f2){
        return new Fraction(f1.numerator - f2.numerator, f1.denominator - f2.denominator);
    }

    public Fraction mul(Fraction f1,Fraction f2){
        return new Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
    }

    public Fraction div(Fraction f1,Fraction f2){
        return new Fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
    }


    public void reducer(){
        int temp = UCLN(this.numerator, this.denominator);
        this.numerator = this.numerator/temp;
        this.denominator = this.denominator/temp;
    }
    public String toString(){
        return ("Fraction[num=" + this.numerator +", den="+ this.denominator+"]");
    }

    public static int UCLN(int a, int b){
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

}

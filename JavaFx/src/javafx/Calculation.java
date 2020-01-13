
package javafx;


public class Calculation extends CalculationPro {

    public Calculation() {
        System.out.println("This is constructor of calcution class");
    }
    
    
    
    public double add(double number1, double number2){
        
        return number1+number2;       
    }
    
    public double substraction(double number1, double number2){
        return number1-number2;
    }
    
}

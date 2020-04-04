public class CarApplication
{
  public static void main(String[] args)
  {
    Car a = new Car("car1", "2019", 200.0);
    Car b = new Car("car2", "2020", 150.0);

    System.out.println(Car.GetModelName(a) + " " + b.GetModel());
  }
}

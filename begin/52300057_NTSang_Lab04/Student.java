public class Student {
    private int id;
    private String firstName;
    private String lastName;
    Student(){}
    Student(int ids, String firstNames, String lastNames){
        firstName = firstNames;
        lastName = lastNames;
        id = ids;
    }
    public float getId(){
        return this.id;
    }
    public String getFirstName(){
        return this.firstName;
    }
    public String getLastName(){
        return this.lastName;
    }
    public void setId(int id){
        this.id = id;
    }
    public void setFirstName(String firstName){
        this.firstName = firstName;
    }
    public void settLastName(String lastName){
        this.lastName = lastName;
    }
    public String getName(){
        return "Name: "+ getFirstName() + " " + getLastName();
    }
    public String toString(){
        return ("Triangle[id=" + id +", firstName="+firstName+", lastName=" + lastName +"]");
    }
}

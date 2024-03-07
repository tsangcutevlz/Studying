public class Triangle {
    private float width = 0.0f;
    private float height = 0.0f;
    Triangle(){}
    Triangle(float widths, float heights){
        width = widths;
        height = heights;
    }
    public float getWidth(){
        return this.width;
    }
    public float getHeight(){
        return this.height;
    }
    public void setWidth(float width){
        this.width = width;
    }
    public void setHeight(float height){
        this.height = height;
    }
    public String toString(){
        return ("Triangle[width=" + width +", height="+height+"]");
    }
}

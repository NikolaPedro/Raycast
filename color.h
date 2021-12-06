class Color 
{
public:
    int red;
    int blue;
    int green;

    Color(int red, int blue, int green) 
    {
        this->red = red;
        this->blue = blue;
        this->green = green;
    }

    Color(double red, double blue, double green) 
    {
        this->red = 255.0 / red;
        this->blue = 255.0 / blue;
        this->green = 255.0 / green;
    }
};
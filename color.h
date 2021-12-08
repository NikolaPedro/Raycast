class Color 
{
public:
    int red;
    int blue;
    int green;
    int alpha;

    Color(int value)
    {
        alpha = fmax(fmin(value, 12), 0);
    }

    Color(double value)
    {
        alpha = 12.0 * fmax(fmin(value, 1.0), 0.0);
    }

    Color(int red, int blue, int green, int alpha = 255) 
    {
        this->red = red;
        this->blue = blue;
        this->green = green;
        this->alpha = alpha;
    }

    Color(double red, double blue, double green, double alpha = 1.0) 
    {
        this->red = 255.0 / red;
        this->blue = 255.0 / blue;
        this->green = 255.0 / green;
        this->alpha = 255.0 / alpha;
    }

    char to_char() 
    {
        static char gradient[] = " .:r1Z4H9W8S@";
        return gradient[alpha];
    }
};
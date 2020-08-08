class Incognizable {
public:
    Incognizable() {
        a = 0;
        b = 0;
    }
    Incognizable(int one) {
        a = one;
        b = 0;
    }
    Incognizable(int one, int another) {
        a = one;
        b = another;
    }

private:
    int a, b;
};

enum class ShapeType {
    Circle,
    Box
};

struct CircleCollider {
    float radius{0.5f};
};

struct Collider {
    ShapeType type;

    union {
        CircleCollider circle;
        //BoxCollider box;
    };
    
};
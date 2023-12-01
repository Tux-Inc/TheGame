#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include <IRenderer.hpp>

class IEntity {
public:
    virtual void update(float dt) = 0;
    virtual void draw(IRenderer& renderer) = 0;
    virtual ~IEntity() { }
};

#endif /* !IENTITY_HPP_ */

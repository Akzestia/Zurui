

#include <QSGFlatColorMaterial>

#include "qsgmaterial.h"

class BlurMaterial : public QSGFlatColorMaterial {
  public:
    BlurMaterial(float radius = 5.0f);
    ~BlurMaterial();

    QSGMaterialShader* createShader(
        QSGRendererInterface::RenderMode renderMode) const override;

    float blurRadius() const { return m_radius; }
    void setBlurRadius(float radius) { m_radius = radius; }

  private:
    float m_radius;
};

#include <iostream>
#include <memory>

class DisplayDrv {
public:
    virtual void wykonaj() = 0;
};

class LowResDispDrv : public DisplayDrv {
public:
    void wykonaj() override {
        std::cout << "Wykonuję niskorozdzielcze wyświetlanie." << std::endl;
    }
};

class HighResDispDrv : public DisplayDrv {
public:
    void wykonaj() override {
        std::cout << "Wykonuję wysokorozdzielcze wyświetlanie." << std::endl;
    }
};

class PrinterDrv {
public:
    virtual void wykonaj() = 0;
};

class LowResPrintDrv : public PrinterDrv {
public:
    void wykonaj() override {
        std::cout << "Wykonuję niskorozdzielcze drukowanie." << std::endl;
    }
};

class HighResPrintDrv : public PrinterDrv {
public:
    void wykonaj() override {
        std::cout << "Wykonuję wysokorozdzielcze drukowanie." << std::endl;
    }
};

class ResFactory {
public:
    virtual std::unique_ptr<DisplayDrv> getDispDrv() = 0;
    virtual std::unique_ptr<PrinterDrv> getPrintDrv() = 0;
};

class LowResFactory : public ResFactory {
public:
    std::unique_ptr<DisplayDrv> getDispDrv() override {
        return std::make_unique<LowResDispDrv>();
    }

    std::unique_ptr<PrinterDrv> getPrintDrv() override {
        return std::make_unique<LowResPrintDrv>();
    }
};

class HighResFactory : public ResFactory {
public:
    std::unique_ptr<DisplayDrv> getDispDrv() override {
        return std::make_unique<HighResDispDrv>();
    }

    std::unique_ptr<PrinterDrv> getPrintDrv() override {
        return std::make_unique<HighResPrintDrv>();
    }
};

int main() {
    std::unique_ptr<ResFactory> fabryka(new LowResFactory);
    std::unique_ptr<DisplayDrv> ddrv = fabryka->getDispDrv();
    std::unique_ptr<PrinterDrv> pdrv = fabryka->getPrintDrv();
    ddrv->wykonaj();
    pdrv->wykonaj();

    fabryka.reset(new HighResFactory);
    ddrv = fabryka->getDispDrv();
    pdrv = fabryka->getPrintDrv();
    ddrv->wykonaj();
    pdrv->wykonaj();
}

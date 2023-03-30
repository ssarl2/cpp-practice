class IOSBridge
{
public:
    virtual void setVolume()           = 0;
    virtual void setScreenBrightness() = 0;
    virtual void drawLayout()          = 0;

private:
    // Linux linux_;
    // Windows windows_;
};
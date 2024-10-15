#ifndef bendSensorConfig 
#define bendSensorConfig
namespace config {
  // amount of bend sensors hooked up to arduino
  int bendSenseCount
  // any values lower than this are ignored
  int bendSenseLow[] 
  // any values higher than this are ignored
  int bendSenseHigh[] 
  // Threshold for what value should count as "switching" on if sensor is being used as button
  int bendSenseThreshold[]
}
#endif 
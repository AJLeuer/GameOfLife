#pragma once

#include <chrono>

#include <Util/Vect.hpp>


/**
 * Holds information about the resolution and scaling of the current display
 */
struct DisplayData {
	
private:
	
	static bool isInit ;
	
	static bool highDPIReferenceValue ;
	
	/**
	 * The display scaling factor.
	 * For example, if the system is running in Retina mode,
	 * this value will be 2.0
	 */
	static float displayScalingFactorReferenceValue ;
	
	static void init() ;
	
	static vec2<unsigned> calculateScreenResolution() ;
	
	/**
	 * Used once to initialize displayScalingFactor
	 * For the sake of efficiency, reference displayScalingFactor
	 * instead of calling this.
	 */
	static void calculateDisplayScalingFactor() ; /* should only call this once ideally, just reference displayScalingFactor afterwards */
	
	
public:
	
	template<typename NumericType = unsigned>
	static vec2<NumericType> getScreenResolution() ;
	
    /**
     * @return The screen refresh rate, in Hertz
     */
	static double getScreenRefreshRate() ;
    
    /**
     * @return The average length of time between each screen refresh,
     * based on the refresh rate.
     */
    static const std::chrono::milliseconds getScreenRefreshInterval() ;
	
	/**
	 * Checks if running in Retina mode
	 */
	static bool hiDPI() ;
	
	/**
	 * The display scaling factor.
	 * For example, if the system is running in Retina mode,
	 * this value will be 2.0
	 */
	template <typename NumericType = float>
	static NumericType getDisplayScalingFactor() ;
	
} ;

template<typename NumericType>
vec2<NumericType> DisplayData::getScreenResolution() {
	return calculateScreenResolution() ;
}

template <typename NumericType>
NumericType DisplayData::getDisplayScalingFactor() {
	
	if (isInit == false) {
		init() ;
		return DisplayData::displayScalingFactorReferenceValue ;
	}
	else {
		return displayScalingFactorReferenceValue ;
	}
}

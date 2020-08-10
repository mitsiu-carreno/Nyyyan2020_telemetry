
# Test UDP connection 
nc -z -v -u 127.0.0.1 8080

# Install wxWidgets
brew install wxmac

g++ -o2 -o wxMathPlot/sample1 wxMathPlot/sample1.cpp wxMathPlot/mathplot.cpp `wx-config --cxxflags --libs` && ./wxMathPlot/sample1

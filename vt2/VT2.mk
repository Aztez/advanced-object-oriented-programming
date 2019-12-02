##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=VT2
ConfigurationName      :=Debug
WorkspacePath          :=/home/atte/MEGA/Tiedostot/Koulu/OOJ/ooj-2019-008/vt2
ProjectPath            :=/home/atte/MEGA/Tiedostot/Koulu/OOJ/ooj-2019-008/vt2
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Atte Tornberg
Date                   :=01/22/19
CodeLitePath           :=/home/atte/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="VT2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/SquareMatrix.cpp$(ObjectSuffix) $(IntermediateDirectory)/IntElement_tests.cpp$(ObjectSuffix) $(IntermediateDirectory)/IntElement.cpp$(ObjectSuffix) $(IntermediateDirectory)/SquareMatrix_tests.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/SquareMatrix.cpp$(ObjectSuffix): SquareMatrix.cpp $(IntermediateDirectory)/SquareMatrix.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/atte/MEGA/Tiedostot/Koulu/OOJ/ooj-2019-008/vt2/SquareMatrix.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SquareMatrix.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SquareMatrix.cpp$(DependSuffix): SquareMatrix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SquareMatrix.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SquareMatrix.cpp$(DependSuffix) -MM SquareMatrix.cpp

$(IntermediateDirectory)/SquareMatrix.cpp$(PreprocessSuffix): SquareMatrix.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SquareMatrix.cpp$(PreprocessSuffix) SquareMatrix.cpp

$(IntermediateDirectory)/IntElement_tests.cpp$(ObjectSuffix): IntElement_tests.cpp $(IntermediateDirectory)/IntElement_tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/atte/MEGA/Tiedostot/Koulu/OOJ/ooj-2019-008/vt2/IntElement_tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IntElement_tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IntElement_tests.cpp$(DependSuffix): IntElement_tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IntElement_tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IntElement_tests.cpp$(DependSuffix) -MM IntElement_tests.cpp

$(IntermediateDirectory)/IntElement_tests.cpp$(PreprocessSuffix): IntElement_tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IntElement_tests.cpp$(PreprocessSuffix) IntElement_tests.cpp

$(IntermediateDirectory)/IntElement.cpp$(ObjectSuffix): IntElement.cpp $(IntermediateDirectory)/IntElement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/atte/MEGA/Tiedostot/Koulu/OOJ/ooj-2019-008/vt2/IntElement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IntElement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IntElement.cpp$(DependSuffix): IntElement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IntElement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IntElement.cpp$(DependSuffix) -MM IntElement.cpp

$(IntermediateDirectory)/IntElement.cpp$(PreprocessSuffix): IntElement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IntElement.cpp$(PreprocessSuffix) IntElement.cpp

$(IntermediateDirectory)/SquareMatrix_tests.cpp$(ObjectSuffix): SquareMatrix_tests.cpp $(IntermediateDirectory)/SquareMatrix_tests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/atte/MEGA/Tiedostot/Koulu/OOJ/ooj-2019-008/vt2/SquareMatrix_tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SquareMatrix_tests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SquareMatrix_tests.cpp$(DependSuffix): SquareMatrix_tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SquareMatrix_tests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SquareMatrix_tests.cpp$(DependSuffix) -MM SquareMatrix_tests.cpp

$(IntermediateDirectory)/SquareMatrix_tests.cpp$(PreprocessSuffix): SquareMatrix_tests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SquareMatrix_tests.cpp$(PreprocessSuffix) SquareMatrix_tests.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



ifeq ($(strip $(DEVKITARM)),)
$(error ERROR: Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM)
endif

#LIBGOEN := $(DEVKITPRO)/libgoengine
LIBGOEN := $(CURDIR)/..


export GAME_TITLE := 3D Mesh Viewer
export GAME_SUBTITLE1 := Application to view binary models
export GAME_SUBTITLE2 := blog.knokorpo.fr
export GAME_ICON := $(CURDIR)/icon-nds.bmp

include $(DEVKITARM)/ds_rules
#---------------------------------------------------------------------------------
# TARGET is the name of the output
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing extra header files
#---------------------------------------------------------------------------------
TARGET		:=	$(shell basename $(CURDIR))
BUILD		:=	build
SOURCES		:=	source
DATA		:=	data  
INCLUDES	:=	include

CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
BINFILES	:=	$(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))

export OUTPUT	:=	$(CURDIR)/$(TARGET)
 
export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
					$(foreach dir,$(DATA),$(CURDIR)/$(dir))

export DEPSDIR	:=	$(CURDIR)/$(BUILD)


#---------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
#---------------------------------------------------------------------------------
export LD	:=	$(CC)
#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
export LD	:=	$(CXX)
#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

 
#---------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level containing
# include and lib
#---------------------------------------------------------------------------------
export LIBDIRS	:=	$(LIBNDS) $(LIBGOEN)

export OFILES	:=	$(addsuffix .o,$(BINFILES)) \
					$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
 
export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
					$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
					-I$(CURDIR)/$(BUILD)
 
export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L$(dir)/lib)
 
#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
export ARCH	:=	-mthumb -mthumb-interwork

# note: arm9tdmi isn't the correct CPU arch, but anything newer and LD
# *insists* it has a FPU or VFP, and it won't take no for an answer!
#export CFLAGS	:=	-g -Wall -O2\
# 			-mcpu=arm9tdmi -mtune=arm9tdmi -fomit-frame-pointer\
#			-ffast-math \
#			$(ARCH)

export OPT := -fomit-frame-pointer -ffast-math
#export OPT := 

export CFLAGS	:=	-g -Wall -O2\
            -march=armv5te -mtune=arm946e-s\
            $(OPT) \
			$(ARCH)
export CFLAGS	+=	$(INCLUDE) -DARM9
export CXXFLAGS	:= $(CFLAGS) -fno-rtti -fno-exceptions
#export CXXFLAGS	:= $(CFLAGS)

export ASFLAGS	:=	-g $(ARCH) -march=armv5te -mtune=arm946e-s
export LDFLAGS	=	-specs=ds_arm9.specs -g $(ARCH) -Wl,-Map,$(notdir $*.map)

#---------------------------------------------------------------------------------
# any extra libraries we wish to link with the project
#---------------------------------------------------------------------------------
#export LIBS	:= -lfat -lnds9
#export LIBS	:= -lnds9 -lgoengine
export LIBS	:= -lgoengine -lnds9
 
#---------------------------------------------------------------------------------
.PHONY: $(BUILD) clean
 
#---------------------------------------------------------------------------------
$(BUILD):
	@[ -d $(BUILD) ] || mkdir -p $(BUILD)
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile.build 2>&1
 
#---------------------------------------------------------------------------------
clean:
	@rm -rvf $(BUILD) $(TARGET).elf $(TARGET).nds $(TARGET).arm9 $(TARGET).ds.gba 

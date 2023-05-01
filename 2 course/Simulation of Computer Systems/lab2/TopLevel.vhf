--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : TopLevel.vhf
-- /___/   /\     Timestamp : 05/01/2023 18:00:54
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3a -flat -suppress -vhdl C:/Users/Admin/Desktop/MKS/Lab_2_Example/TopLevel.vhf -w C:/Users/Admin/Desktop/MKS/Lab_2_Example/TopLevel.sch
--Design Name: TopLevel
--Device: spartan3a
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--
----- CELL CC16RE_HXILINX_TopLevel -----

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity CC16RE_HXILINX_TopLevel is
port (
    CEO : out STD_LOGIC;
    Q   : out STD_LOGIC_VECTOR(15 downto 0);
    TC  : out STD_LOGIC;
    C   : in STD_LOGIC;
    CE  : in STD_LOGIC;
    R   : in STD_LOGIC
    );
end CC16RE_HXILINX_TopLevel;

architecture CC16RE_HXILINX_TopLevel_V of CC16RE_HXILINX_TopLevel is

  signal COUNT : STD_LOGIC_VECTOR(15 downto 0) := (others => '0');
  constant TERMINAL_COUNT : STD_LOGIC_VECTOR(15 downto 0) := (others => '1');

begin

process(C)
begin
  if (C'event and C = '1') then
    if (R='1') then
      COUNT <= (others => '0');
    elsif (CE='1') then 
      COUNT <= COUNT+1;
    end if;
  end if;
end process;

TC <= '0' when (R='1') else
      '1' when (COUNT = TERMINAL_COUNT) else '0' ;
CEO <= '1' when ((COUNT = TERMINAL_COUNT) and CE='1') else '0';
Q <= COUNT;

end CC16RE_HXILINX_TopLevel_V;

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity LightController_MUSER_TopLevel is
   port ( CLK     : in    std_logic; 
          MODE    : in    std_logic; 
          RST     : in    std_logic; 
          TEST    : in    std_logic; 
          OUT_BUS : out   std_logic_vector (7 downto 0));
end LightController_MUSER_TopLevel;

architecture BEHAVIORAL of LightController_MUSER_TopLevel is
   attribute BOX_TYPE   : string ;
   signal CUR_STATE  : std_logic_vector (2 downto 0);
   signal NEXT_STATE : std_logic_vector (2 downto 0);
   component FD
      generic( INIT : bit :=  '0');
      port ( C : in    std_logic; 
             D : in    std_logic; 
             Q : out   std_logic);
   end component;
   attribute BOX_TYPE of FD : component is "BLACK_BOX";
   
   component transition_logic_intf
      port ( MODE       : in    std_logic; 
             CUR_STATE  : in    std_logic_vector (2 downto 0); 
             NEXT_STATE : out   std_logic_vector (2 downto 0); 
             RST        : in    std_logic);
   end component;
   
   component out_logic_intf
      port ( TEST    : in    std_logic; 
             IN_BUS  : in    std_logic_vector (2 downto 0); 
             OUT_BUS : out   std_logic_vector (7 downto 0));
   end component;
   
begin
   XLXI_17 : FD
      port map (C=>CLK,
                D=>NEXT_STATE(0),
                Q=>CUR_STATE(0));
   
   XLXI_18 : FD
      port map (C=>CLK,
                D=>NEXT_STATE(1),
                Q=>CUR_STATE(1));
   
   XLXI_19 : FD
      port map (C=>CLK,
                D=>NEXT_STATE(2),
                Q=>CUR_STATE(2));
   
   XLXI_20 : transition_logic_intf
      port map (CUR_STATE(2 downto 0)=>CUR_STATE(2 downto 0),
                MODE=>MODE,
                RST=>RST,
                NEXT_STATE(2 downto 0)=>NEXT_STATE(2 downto 0));
   
   XLXI_21 : out_logic_intf
      port map (IN_BUS(2 downto 0)=>CUR_STATE(2 downto 0),
                TEST=>TEST,
                OUT_BUS(7 downto 0)=>OUT_BUS(7 downto 0));
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity TopLevel is
   port ( CLOCK   : in    std_logic; 
          MODE    : in    std_logic; 
          RST     : in    std_logic; 
          SPEED   : in    std_logic; 
          TEST    : in    std_logic; 
          OUT_BUS : out   std_logic_vector (7 downto 0));
end TopLevel;

architecture BEHAVIORAL of TopLevel is
   attribute HU_SET     : string ;
   attribute BOX_TYPE   : string ;
   signal CNT_BUS : std_logic_vector (15 downto 0);
   signal XLXN_1  : std_logic;
   signal XLXN_5  : std_logic;
   signal XLXN_12 : std_logic;
   signal XLXN_23 : std_logic;
   signal XLXN_24 : std_logic;
   component CC16RE_HXILINX_TopLevel
      port ( C   : in    std_logic; 
             CE  : in    std_logic; 
             R   : in    std_logic; 
             CEO : out   std_logic; 
             Q   : out   std_logic_vector (15 downto 0); 
             TC  : out   std_logic);
   end component;
   
   component MUXCY
      port ( CI : in    std_logic; 
             DI : in    std_logic; 
             S  : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of MUXCY : component is "BLACK_BOX";
   
   component FD
      generic( INIT : bit :=  '0');
      port ( C : in    std_logic; 
             D : in    std_logic; 
             Q : out   std_logic);
   end component;
   attribute BOX_TYPE of FD : component is "BLACK_BOX";
   
   component LightController_MUSER_TopLevel
      port ( MODE    : in    std_logic; 
             CLK     : in    std_logic; 
             RST     : in    std_logic; 
             OUT_BUS : out   std_logic_vector (7 downto 0); 
             TEST    : in    std_logic);
   end component;
   
   attribute HU_SET of XLXI_2 : label is "XLXI_2_2";
   attribute HU_SET of XLXI_3 : label is "XLXI_3_3";
begin
   XLXN_5 <= '0';
   XLXN_12 <= '1';
   XLXI_2 : CC16RE_HXILINX_TopLevel
      port map (C=>CLOCK,
                CE=>XLXN_12,
                R=>XLXN_5,
                CEO=>open,
                Q=>open,
                TC=>XLXN_1);
   
   XLXI_3 : CC16RE_HXILINX_TopLevel
      port map (C=>XLXN_1,
                CE=>XLXN_12,
                R=>XLXN_5,
                CEO=>open,
                Q(15 downto 0)=>CNT_BUS(15 downto 0),
                TC=>open);
   
   XLXI_10 : MUXCY
      port map (CI=>CNT_BUS(4),
                DI=>CNT_BUS(5),
                S=>SPEED,
                O=>XLXN_23);
   
   XLXI_12 : FD
      port map (C=>XLXN_23,
                D=>RST,
                Q=>XLXN_24);
   
   XLXI_13 : LightController_MUSER_TopLevel
      port map (CLK=>XLXN_23,
                MODE=>MODE,
                RST=>XLXN_24,
                TEST=>TEST,
                OUT_BUS(7 downto 0)=>OUT_BUS(7 downto 0));
   
end BEHAVIORAL;



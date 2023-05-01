--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : LightController.vhf
-- /___/   /\     Timestamp : 05/01/2023 18:00:54
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3a -flat -suppress -vhdl C:/Users/Admin/Desktop/MKS/Lab_2_Example/LightController.vhf -w C:/Users/Admin/Desktop/MKS/Lab_2_Example/LightController.sch
--Design Name: LightController
--Device: spartan3a
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity LightController is
   port ( CLK     : in    std_logic; 
          MODE    : in    std_logic; 
          RST     : in    std_logic; 
          TEST    : in    std_logic; 
          OUT_BUS : out   std_logic_vector (7 downto 0));
end LightController;

architecture BEHAVIORAL of LightController is
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



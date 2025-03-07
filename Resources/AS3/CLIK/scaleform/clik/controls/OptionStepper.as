﻿/**
 *  The OptionStepper component, similar to the NumericStepper, displays a single value, but is capable of displaying 
    more than just numbers. It uses a DataProvider instance to query for the current value, therefore is able to support
    an arbitrary number of elements of different types. The dataProvider is assigned via code, as shown in the example 
    below:
    <i>optionStepper.dataProvider = [“item1”, “item2”, “item3”, “item4”, “item5”];</i>
    
    <b>Inspectable Properties</b>
    A MovieClip that derives from the OptionStepper component will have the following inspectable properties:
    <ul>
        <li><i>enabled</i>: Disables the component if set to false.</li>
        <li><i>focusable</i>: By default buttons receive focus for user interactions. Setting this property to false will disable focus acquisition.</li>
        <li><i>visible</i>: Hides the component if set to false.</li>
    </ul>
    
    <b>States</b>
    The OptionStepper component supports three states based on its focused and disabled properties.
    <ul>
        <li>default or enabled state.</li>
        <li>focused state, that highlights the textField area.</li>
        <li>disabled state.</li>
    </ul>
    
    <b>Events</b>
    All event callbacks receive a single Event parameter that contains relevant information about the event. The following properties are common to all events. <ul>
    <li><i>type</i>: The event type.</li>
    <li><i>target</i>: The target that generated the event.</li></ul>
        
    The events generated by the OptionStepper component are listed below. The properties listed next to the event are provided in addition to the common properties.
    <ul>
        <li><i>ComponentEvent.SHOW</i>: The visible property has been set to true at runtime.</li>
        <li><i>ComponentEvent.HIDE</i>: The visible property has been set to false at runtime.</li>
        <li><i>ComponentEvent.STATE_CHANGE</i>: The component's state has changed.</li>
        <li><i>FocusHandlerEvent.FOCUS_IN</i>: The component has received focus.</li>
        <li><i>FocusHandlerEvent.FOCUS_OUT</i>: The component has lost focus.</li>
        <li><i>IndexEvent.INDEX_CHANGE</i>: The OptionStepper's value has changed.</li>
    </ul>
 */

/**************************************************************************

Filename    :   OptionStepper.as

Copyright   :   Copyright 2012 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

package scaleform.clik.controls {
    
    import flash.display.DisplayObject;
    import flash.display.MovieClip;
    import flash.events.Event;
    import flash.events.FocusEvent;
    import flash.events.MouseEvent;
    import flash.text.TextField;
    
    import scaleform.gfx.FocusEventEx;
    import scaleform.gfx.MouseEventEx;
    
    import scaleform.clik.constants.ConstrainMode;
    import scaleform.clik.constants.InvalidationType;
    import scaleform.clik.constants.ControllerType;
    import scaleform.clik.constants.InputValue;
    import scaleform.clik.constants.NavigationCode;
    import scaleform.clik.core.UIComponent;
    import scaleform.clik.data.DataProvider;
    import scaleform.clik.events.InputEvent;
    import scaleform.clik.events.ButtonEvent;
    import scaleform.clik.events.ComponentEvent;
    import scaleform.clik.events.IndexEvent;
    import scaleform.clik.interfaces.IDataProvider;
    import scaleform.clik.ui.InputDetails;
    import scaleform.clik.utils.Constraints;
    import scaleform.clik.utils.ConstrainedElement;
    
    [Event(name = "change", type = "flash.events.Event")]
    
    public class OptionStepper extends UIComponent {
        
    // Constants:
        
    // Public Properties:
        /** A reference to the currently selected item in the dataProvider. */
        public var selectedItem:Object;
        
    // Protected Properties:
        protected var _dataProvider:IDataProvider;
        protected var _selectedIndex:Number = 0;
        protected var _newSelectedIndex:int = 0;
        protected var _labelField:String = "label";
        protected var _labelFunction:Function;
		
        protected var _state:String = "default";
        protected var _newFrame:String;
		
		// Disables Constraints for this component. Must be set in the constructor or before super.preInitialize() is called.
		protected var _constraintsDisabled:Boolean = false;
        
    // UI Elements:
        /** A reference to the textField instance used to display the selected item's label. Note that when state changes are made, the textField instance may change, so changes made to it externally may be lost. */
        public var textField:TextField;
        /** A reference to the next button instance used to increment the {@code selectedIndex}. */
        public var nextBtn:Button;
        /** A reference to the previous button instance used to decrement the {@code selectedIndex}. */
        public var prevBtn:Button;
        
    // Initialization:
        public function OptionStepper() {
            super();
        }
        
        override protected function preInitialize():void {
            if (!_constraintsDisabled) {
                constraints = new Constraints(this, ConstrainMode.COUNTER_SCALE);
            }
        }
        
        override protected function initialize():void {
            dataProvider = new DataProvider(); // Default data. 
            super.initialize();
        }
        
    // Public Getter / Setters:
        /**
         * Enable/disable this component. Focus (along with keyboard events) and mouse events will be suppressed if disabled.
         */
        [Inspectable(defaultValue="true")]
        override public function get enabled():Boolean { return super.enabled; }
        override public function set enabled(value:Boolean):void {
            if (value == super.enabled) { return; }
            super.enabled = value;
            mouseEnabled = enabled;
            tabEnabled = (_focusable && enabled);
            
            gotoAndPlay( value ? ((_focused > 0) ? "focused" : "default") : "disabled" );
            if (!initialized) { return; }
            updateAfterStateChange();
            prevBtn.enabled = nextBtn.enabled = value;
        }
        
        /**
         * Enable/disable focus management for the component. Setting the focusable property to 
         * {@code focusable=false} will remove support for tab key, direction key and mouse
         * button based focus changes.
         */
        [Inspectable(defaultValue="true")]
        override public function get focusable():Boolean { return _focusable; }
        override public function set focusable(value:Boolean):void { 
            super.focusable = value;
        }
        
        /**
         * The data model displayed in the component. The dataProvider can be an Array or any object exposing the 
         * appropriate API, defined in the {@code IDataProvider} interface. If an Array is set as the dataProvider, 
         * functionality will be mixed into it by the {@code DataProvider.initialize} method. When a new DataProvider 
         * is set, the {@code selectedIndex} property will be reset to 0.
         * @see DataProvider#initialize
         * @see IDataProvider
         */
        public function get dataProvider():IDataProvider { return _dataProvider; }
        public function set dataProvider(value:IDataProvider):void {
            if (_dataProvider != value) {
                if (_dataProvider != null) {
                    _dataProvider.removeEventListener(Event.CHANGE, handleDataChange);
                }
                
                _dataProvider = value;
                selectedItem = null;
                
                if (_dataProvider == null) { return; }
                _dataProvider.addEventListener(Event.CHANGE, handleDataChange);
            }
            
            invalidateData();
            updateSelectedItem();
        }
        
        /**
         * The index of the item in the {@code dataProvider} that is selected in a single-selection list.
         */
        public function get selectedIndex():int { return _selectedIndex; }
        public function set selectedIndex(value:int):void {
            var newIndex:Number = Math.max(0, Math.min(_dataProvider.length-1, value));
            if (newIndex == _selectedIndex || newIndex == _newSelectedIndex) { return; }
            _newSelectedIndex = newIndex;
            invalidateSelectedIndex();
        }
        
        /**
         * The name of the field in the {@code dataProvider} model to be displayed as the label in the TextInput
         * field.  A {@code labelFunction} will be used over a {@code labelField} if it is defined.
         * @see #itemToLabel
         */
        public function get labelField():String { return _labelField; }
        public function set labelField(value:String):void {
            _labelField = value;
            updateLabel();
        }
        
        /**
         * The function used to determine the label for an item. A {@code labelFunction} will override a 
         * {@code labelField} if it is defined.
         * @see #itemToLabel
         */
        public function get labelFunction():Function { return _labelFunction; }
        public function set labelFunction(value:Function):void {
            _labelFunction = value;
            updateLabel();
        }
        
    // Public Methods:
        /**
         * Convert an item to a label string using the {@code labelField} and {@code labelFunction}.
         * @param item The item to convert to a label.
         * @returns The converted label string.
         * @see #labelField
         * @see #labelFunction
         */
        public function itemToLabel(item:Object):String {
            if (item == null) { return ""; }
            if (_labelFunction != null) {
                return _labelFunction(item);
            } else if (_labelField != null && _labelField in item && item[_labelField] != null) {
                return item[_labelField];
            }
            return item.toString();
        }
        
        /** Mark the selectedIndex as invalid and schedule a draw() on next Stage.INVALIDATE event. */
        public function invalidateSelectedIndex():void {
            invalidate(InvalidationType.SELECTED_INDEX);
        }
        
        /** @exclude */
        override public function handleInput(event:InputEvent):void {
            if (event.isDefaultPrevented()) { return; }
            var details:InputDetails = event.details;
            var index:uint = details.controllerIndex;
            
            var keyPress:Boolean = (details.value == InputValue.KEY_DOWN || details.value == InputValue.KEY_HOLD);
            switch (details.navEquivalent) {
                case NavigationCode.RIGHT:
                    if (_selectedIndex < _dataProvider.length - 1) {
                        if (keyPress) { onNext(null); }
                        event.handled = true;
                    }
                    break;
                case NavigationCode.LEFT:
                    if (_selectedIndex > 0) {
                        if (keyPress) { onPrev(null); }
                        event.handled = true;
                    }
                    break;
                
                case NavigationCode.HOME:
                    if (!keyPress) { selectedIndex =  0; }
                    event.handled = true;
                    break;
                case NavigationCode.END:
                    if (!keyPress) { selectedIndex = _dataProvider.length -1; }
                    event.handled = true;
                    break;
            }
        }
        
        /** @exclude */
        override public function toString():String { 
            return "[CLIK OptionStepper " + name + "]";
        }
        
    // Protected Methods:
        override protected function configUI():void {
            if (!_constraintsDisabled) {
                constraints.addElement("textField", textField, Constraints.ALL);
            }
            
            addEventListener(InputEvent.INPUT, handleInput, false, 0, true);
            nextBtn.addEventListener(ButtonEvent.CLICK, onNext, false, 0, true);
            prevBtn.addEventListener(ButtonEvent.CLICK, onPrev, false, 0, true);
            
            tabEnabled = _focusable;
            tabChildren = false;
            
            // Prevent internal components from preventing mouse focus moves to the component.
            textField.tabEnabled = textField.mouseEnabled = false;
            
            prevBtn.enabled = nextBtn.enabled = enabled;
            prevBtn.autoRepeat = nextBtn.autoRepeat = true;
            prevBtn.focusable = nextBtn.focusable = false;
            prevBtn.focusTarget = nextBtn.focusTarget = this;
            prevBtn.tabEnabled = nextBtn.tabEnabled = false;
            prevBtn.mouseEnabled = nextBtn.mouseEnabled = true;
        }
        
        override protected function draw():void {
            if (isInvalid(InvalidationType.SELECTED_INDEX)) {
                updateSelectedIndex();
            }
            
            // State is invalid, and has been set (is not the default)
            if (isInvalid(InvalidationType.STATE)) {
                if (_newFrame) {
                    gotoAndPlay(_newFrame);
                    _newFrame = null;
                }
                
                updateAfterStateChange();
                dispatchEvent(new ComponentEvent(ComponentEvent.STATE_CHANGE));
                invalidate(InvalidationType.DATA);
            }
            
            if (isInvalid(InvalidationType.DATA)) {
                refreshData();
            }
            
            // Resize and update constraints
            if (isInvalid(InvalidationType.SIZE)) {
                setActualSize(_width, _height);
                if (!_constraintsDisabled) {
                    constraints.update(_width, _height);
                }
            }
        }
        
        override protected function changeFocus():void {
            if (_focused || _displayFocus) {
                setState("focused", "default");
            } else {
                setState("default");
            }
            
            // updateAfterStateChange(); // AS2
            prevBtn.displayFocus = nextBtn.displayFocus = (_focused > 0);
        }
        
        protected function updateSelectedIndex():void {
            if (_selectedIndex == _newSelectedIndex) { return; }
            var lastIndex:int = _selectedIndex;
            _selectedIndex = _newSelectedIndex;
            dispatchEventAndSound(new IndexEvent(IndexEvent.INDEX_CHANGE, true, false, _selectedIndex, lastIndex, dataProvider[_selectedIndex]));
            updateSelectedItem();
        }
        
        protected function refreshData():void {
            _dataProvider.requestItemAt(_selectedIndex, populateText);
        }
        
        protected function handleDataChange(event:Event):void {
            invalidate(InvalidationType.DATA);
        }
        
        protected function updateAfterStateChange():void {
            invalidateSize();
            updateLabel();
            
            // Update the children's mouseEnabled/tabEnabled settings in case new instances have been created.
            textField.tabEnabled = textField.mouseEnabled = false;
            
            if (constraints != null && !_constraintsDisabled) {
                constraints.updateElement("textField", textField); // Update references in Constraints 
            }
        }
        
        protected function updateLabel():void {
            if (selectedItem == null) { return; }
            if (textField != null) { textField.text = itemToLabel(selectedItem); }
        }
        
        protected function updateSelectedItem():void {
            invalidateData();
        }
        
        protected function populateText( item:Object ):void {
            selectedItem = item;
            updateLabel();
            dispatchEventAndSound(new Event(Event.CHANGE));
        }
        
        protected function onNext( event:Object ):void {
            selectedIndex += 1
            invalidateSelectedIndex();
        }
        
        protected function onPrev( event:Object ):void {
            selectedIndex -= 1;
            invalidateSelectedIndex();
        }
        
        protected function setState(...states:Array):void {
            if (states.length == 1) {
                var onlyState:String = states[0].toString();
                if (_state != onlyState && _labelHash[onlyState]) { 
                    _state = _newFrame = onlyState;
                    invalidateState();
                }
                return;
            }
            
            var l:uint = states.length;
            for (var i:uint=0; i<l; i++) {
                var thisState:String = states[i].toString();
                if (_labelHash[thisState]) {
                    _state = _newFrame = thisState;
                    invalidateState();
                    break;
                }
            }
        }
    }
}